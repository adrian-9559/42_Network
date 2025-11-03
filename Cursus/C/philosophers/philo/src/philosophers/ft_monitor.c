/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:45:00 by automated         #+#    #+#             */
/*   Updated: 2025/10/20 17:55:20 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Checks the state of philosopher i: detects if they have died of
 * starvation or updates the all-finished indicator. Locks philos[i].meal_mtx
 * while reading/updating last_meal_ms and meals_eaten.
 *
 * If a death is detected:
 *   - sets data->stop = 1,
 *   - computes data->death_time as (now - data->start_time),
 *   - prints "<timestamp> <id> died" while protecting the print with
 * 		data->print,
 *   - returns 1.
 *
 * If a meals-per-philosopher requirement exists and the philosopher hasn't
 * reached it, sets *all_finished = 0. Unlocks the mutex before returning.
 *
 * SPANISH: Comprueba el estado del filósofo i: detecta si ha muerto por
 * inanición o actualiza el indicador de que todos han terminado. Bloquea
 * philos[i].meal_mtx mientras lee/actualiza last_meal_ms y meals_eaten.
 *
 * Si se detecta una muerte:
 *   - establece data->stop = 1,
 *   - calcula data->death_time como (now - data->start_time),
 *   - imprime "<timestamp> <id> died" protegiendo la impresión con data->print,
 *   - devuelve 1.
 *
 * Si existe un requisito de comidas por filósofo y éste no lo ha cumplido,
 * marca *all_finished = 0. Desbloquea el mutex antes de salir.
 *
 * @param data Pointer to the global data structure. / El puntero a la estructura
 *             de datos global.
 * @param philos Pointer to the array of philosophers. / El puntero al arreglo de
 *               filósofos.
 * @param i Index of the philosopher to check. / Índice del filósofo a comprobar.
 * @param all_finished Pointer to a flag set to 0 if any philosopher hasn't
 *                     completed the required meals. / Puntero a una bandera que
 *                     se pone a 0 si algún filósofo no ha completado las comidas
 *                     requeridas.
 *
 * @returns 1 if the philosopher died, 0 otherwise. / 1 si el filósofo murió,
 * 			0 en caso contrario.
 */
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
		printf("%ld %d died\n", timestamp, philos[i].id);
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
		usleep(100);
	}
	return (NULL);
}
