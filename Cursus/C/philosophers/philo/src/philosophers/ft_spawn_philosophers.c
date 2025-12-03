/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spawn_philosophers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:58:37 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/28 16:54:36 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Spawns threads for each philosopher to run their routines.
 * Staggers the start of odd-indexed philosophers by 1 ms to reduce contention.
 *
 * SPANISH: Crea hilos para que cada filósofo ejecute sus rutinas.
 * Desfase el inicio de los filósofos con índice impar en 1 ms para reducir
 * la contención.
 *
 * @param philosophers Pointer to the array of philosophers. /
 *                     Puntero al array de filósofos.
 *
 * @returns 0 on success, 1 on failure. / 0 en caso de éxito, 1 en caso de fallo.
 */
int	ft_spawn_philosophers(t_philosopher *philosophers)
{
	int	i;
	int	n;

	if (!philosophers)
		return (1);
	n = philosophers[0].data->number_of_philosophers;

	/* set the global start_time now (at actual spawn start) so timing is based
	   on when threads are created rather than when mutexes were initialized */
	philosophers[0].data->start_time = ft_now_ms();
	/* initialize last meal for all philosophers first to have consistent baseline
	   Use start_time initially, but after spawning threads we will refresh to
	   the real current time so the monitor doesn't mark slow-starting threads
	   as dead. */
	i = 0;
	while (i < n)
	{
		philosophers[i].last_meal_ms = philosophers[i].data->start_time;
		i++;
	}

	/* create even indexed philosophers first, then odd indexed.
	   For large N this reduces immediate fork contention. */
	i = 0;
	while (i < n)
	{
		if (pthread_create(&philosophers[i].thread, NULL,
				&ft_philo_routine, &philosophers[i]) != 0)
			return (1);
		/* small additional pause after creation for very large sims */
		if (n > 100)
			usleep(2000);
		/* small pause for large sims to let some threads progress (even indices) */
		if (n > 100 && (i % 2 == 0))
			usleep(8000);
		i += 2;
	}
	i = 1;
	while (i < n)
	{
		if (pthread_create(&philosophers[i].thread, NULL,
				&ft_philo_routine, &philosophers[i]) != 0)
			return (1);
		if (n > 100)
			usleep(2000);
		if (n > 100 && (i % 2 == 1))
			usleep(8000);
		i += 2;
	}
	/* All philosopher threads created: refresh last_meal_ms to now so monitor
	   uses a realistic baseline. Add a short pause to let threads start. */
	usleep(1000);
	i = 0;
	while (i < n)
	{
		philosophers[i].last_meal_ms = ft_now_ms();
		i++;
	}
	return (0);
}
