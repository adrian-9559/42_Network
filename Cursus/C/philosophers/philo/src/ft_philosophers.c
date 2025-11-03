/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:09:01 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 18:03:27 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/**
 * ENGLISH: Starts the monitor thread for the philosophers simulation.
 *
 * SPANISH: Inicia el hilo monitor para la simulación de filósofos.
 *
 * @param monitor_thread Pointer to the monitor thread variable. /
 *                       Puntero a la variable del hilo monitor.
 * @param philosophers Pointer to the array of philosophers. /
 *                     Puntero al array de filósofos.
 * @param name_function Name of the calling function for error reporting. /
 *                      Nombre de la función que llama para reportar errores.
 *
 * @returns 0 on success, 1 on failure. / 0 en caso de éxito, 1 en caso de fallo.
 */
static int	ft_start_monitor_thread(pthread_t *monitor_thread,
	t_philosopher *philosophers, const char *name_function)
{
	if (pthread_create(monitor_thread, NULL, &ft_monitor, philosophers) != 0)
	{
		ft_error(name_function, (char *[2]){"Failed to spawn monitor", NULL});
		return (1);
	}
	return (0);
}

/**
 * ENGLISH: Joins all philosopher threads.
 *
 * SPANISH: Espera a que terminen todos los hilos de filósofos.
 *
 * @param philosophers Pointer to the array of philosophers. /
 *                     Puntero al array de filósofos.
 * @param number_of_philosophers The number of philosophers. /
 *                               El número de filósofos.
 * @returns 0 on success. / 0 en caso de éxito.
 */
static int	ft_join_philosopher_threads(t_philosopher *philosophers,
	int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_join(philosophers[i].thread, NULL);
		i++;
	}
	return (0);
}

/**
 * ENGLISH: Main function to run the philosophers simulation.
 *
 * SPANISH: Función principal para ejecutar la simulación de filósofos.
 *
 * @param data Pointer to the simulation data. / Puntero a los datos de la
 * 		simulación.
 *
 * @returns 0 on success, 1 on failure. / 0 en caso de éxito, 1 en caso de fallo.
 */
int	ft_philosophers(t_data *data)
{
	t_philosopher	*philosophers;
	pthread_t		monitor_thread;

	philosophers = ft_create_philosophers(data);
	if (!philosophers)
		return (1);
	if (ft_spawn_philosophers(philosophers) != 0)
	{
		ft_error(NAME_FT_PHILOSOPHERS_C,
			(char *[2]){"Failed to spawn threads", NULL});
		ft_destroy_philosophers(philosophers);
		return (1);
	}
	if (ft_start_monitor_thread(&monitor_thread, philosophers,
			NAME_FT_PHILOSOPHERS_C) != 0)
	{
		ft_destroy_philosophers(philosophers);
		return (1);
	}
	ft_join_philosopher_threads(philosophers, data->number_of_philosophers);
	pthread_join(monitor_thread, NULL);
	ft_destroy_philosophers(philosophers);
	return (0);
}
