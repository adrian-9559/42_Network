/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:45:00 by automated         #+#    #+#             */
/*   Updated: 2025/12/17 15:57:24 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Writes a number into a buffer starting at the given position.
 *
 * SPANISH: Escribe un número en un buffer comenzando en la posición dada.
 *
 * @param buf The buffer to write into. / El buffer donde escribir.
 * @param pos The position in the buffer to start writing. /
 *            La posición en el buffer para comenzar a escribir.
 * @param val The number to write. / El número a escribir.
 *
 * @returns The new position in the buffer after writing the number. /
 *          La nueva posición en el buffer después de escribir el número.
 */
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

/**
 * ENGLISH: Appends a string to a buffer starting at the given position.
 *
 * SPANISH: Añade una cadena a un buffer comenzando en la posición dada.
 *
 * @param buf The buffer to write into. / El buffer donde escribir.
 * @param pos The position in the buffer to start writing. /
 *            La posición en el buffer para comenzar a escribir.
 * @param s The string to append. / La cadena a añadir.
 *
 * @returns The new position in the buffer after appending the string. /
 *          La nueva posición en el buffer después de añadir la cadena.
 */
static int	append_str(char *buf, int pos, const char *s)
{
	while (*s)
		buf[pos++] = *s++;
	return (pos);
}

/**
 * ENGLISH: Prints the death message for a philosopher.
 *
 * SPANISH: Imprime el mensaje de muerte de un filósofo.
 *
 * @param timestamp The timestamp of the death. / El timestamp de la muerte.
 * @param id The ID of the philosopher who died. / El ID del filósofo que murió.
 *
 * @returns void. / void.
 */
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
	write(1, buf, pos);
}

/**
 * ENGLISH: Checks the status of a philosopher to see if they have died or
 * completed their meals.
 *
 * SPANISH: Comprueba el estado de un filósofo para ver si ha muerto o
 * ha completado sus comidas.
 *
 * @param data Pointer to the shared data structure. /
 *             Puntero a la estructura de datos compartida.
 * @param philos Pointer to the array of philosophers. /
 *               Puntero al array de filósofos.
 * @param i The index of the philosopher to check. / El índice del filósofo a
 * 			comprobar.
 * @param all_finished Pointer to an integer that will be set to 0 if any
 *                     philosopher has not finished eating. /
 *                     Puntero a un entero que se establecerá en 0 si algún
 *                     filósofo no ha terminado de comer.
 *
 * @returns 1 if the philosopher has died, 0 otherwise. /
 *          1 si el filósofo ha muerto, 0 en caso contrario.
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
 * ENGLISH: Monitor thread function that checks the status of all philosophers.
 * 			Stops the simulation if a philosopher dies or all have finished
 * 			eating.
 *
 * SPANISH: Función del hilo monitor que comprueba el estado de todos los
 * 			filósofos.
 * 			Detiene la simulación si un filósofo muere o todos han terminado
 * 			de comer.
 *
 * @param arg Pointer to the array of philosophers. /
 *            Puntero al array de filósofos.
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
