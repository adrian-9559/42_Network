/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:45:00 by automated         #+#    #+#             */
/*   Updated: 2025/12/16 00:24:10 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static int	write_number(char *buf, int pos, long val)
{
	char	tmp[32];
	int		npos;

	npos = 0;
	if (val == 0)
		tmp[npos++] = '0';
	while (val > 0 && npos < (int) sizeof(tmp))
	{
		tmp[npos++] = (char)('0' + (val % 10));
		val /= 10;
	}
	while (npos > 0)
		buf[pos++] = tmp[--npos];
	return (pos);
}

static int	append_str(char *buf, int pos, const char *s)
{
	while (*s)
		buf[pos++] = *s++;
	return (pos);
}

static void	print_death(long timestamp, int id)
{
	char	buf[64];
	int		pos;

	pos = 0;
	pos = write_number(buf, pos, timestamp);
	buf[pos++] = ' ';
	pos = write_number(buf, pos, id);
	buf[pos++] = ' ';
	pos = append_str(buf, pos, "died\n");
	(void)write(1, buf, pos);
}

static int	ft_check_philo(t_data *data, t_philosopher *philos, int i,
	int *all_finished)
{
	long	now;
	long	timestamp;

	pthread_mutex_lock(&philos[i].meal_mtx);
	now = ft_now_ms();
	if ((now - philos[i].last_meal_ms) > data->time_to_die)
	{
		pthread_mutex_lock(&data->print);
		pthread_mutex_unlock(&philos[i].meal_mtx);
		data->stop = 1;
		data->death_time = now - data->start_time;
		timestamp = data->death_time;
		print_death(timestamp, philos[i].id);
		pthread_mutex_unlock(&data->print);
		return (1);
	}
	if (data->number_of_times_each_philosopher_must_eat > 0)
	{
		if (philos[i].meals_eaten
			< data->number_of_times_each_philosopher_must_eat)
			*all_finished = 0;
	}
	pthread_mutex_unlock(&philos[i].meal_mtx);
	return (0);
}

/**
 * ENGLISH: Monitor function that continuously checks the state of all
 * philosophers to detect deaths or completion of required meals.
 *
 * The function loops until data->stop is set. In each iteration, it checks
 * each philosopher using ft_check_philo(). If a philosopher dies, it exits
 * immediately. If all philosophers have completed the required meals, it sets
 * data->stop and exits.
 *
 * SPANISH: Función de monitor que comprueba continuamente el estado de todos
 * los filósofos para detectar muertes o la finalización de las comidas
 * requeridas.
 *
 * La función se ejecuta en un bucle hasta que se establece data->stop. En
 * cada iteración, comprueba cada filósofo usando ft_check_philo(). Si un
 * filósofo muere, sale inmediatamente. Si todos los filósofos han completado
 * las comidas requeridas, establece data->stop y sale.
 *
 * @param arg Pointer to the first philosopher in the array. /
 *            Puntero al primer filósofo del array.
 *
 * @returns NULL. / NULL.
 */
void	*ft_monitor(void *arg)
{
	t_philosopher	*philos;
	t_data			*data;
	int				array[2];

	philos = (t_philosopher *)arg;
	data = philos->data;
	while (!data->stop)
	{
		array[0] = 0;
		array[1] = 1;
		while (array[0] < data->number_of_philosophers)
		{
			if (ft_check_philo(data, philos, array[0], &array[1]))
				return (NULL);
			array[0]++;
		}
		if (data->number_of_times_each_philosopher_must_eat > 0 && array[1])
		{
			data->stop = 1;
			return (NULL);
		}
		usleep(500);
	}
	return (NULL);
}
