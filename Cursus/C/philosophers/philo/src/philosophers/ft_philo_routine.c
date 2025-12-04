/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:06:45 by adriescr          #+#    #+#             */
/*   Updated: 2025/12/04 17:16:40 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Checks if the philosopher has reached the required number of meals.
 *
 * SPANISH: Comprueba si el filósofo ha alcanzado el número requerido de comidas.
 *
 * @param philo Pointer to the philosopher structure. /
 *              Puntero a la estructura del filósofo.
 *
 * @returns 1 if the philosopher has finished eating, 0 otherwise. /
 *          1 si el filósofo ha terminado de comer, 0 en caso contrario.
 */
static int	ft_check_philo_finished(t_philosopher *philo)
{
	int	limit;
	int	finished;

	limit = philo->data->number_of_times_each_philosopher_must_eat;
	if (limit <= 0)
		return (0);
	pthread_mutex_lock(&philo->meal_mtx);
	if (philo->meals_eaten >= limit)
	{
		philo->finished = 1;
		finished = 1;
	}
	else
		finished = 0;
	pthread_mutex_unlock(&philo->meal_mtx);
	return (finished);
}

/**
 * ENGLISH: Handles the sleeping and thinking actions of the philosopher.
 *
 * SPANISH: Maneja las acciones de dormir y pensar del filósofo.
 *
 * @param philo Pointer to the philosopher structure. /
 *              Puntero a la estructura del filósofo.
 */
static void	ft_sleep_and_think(t_philosopher *philo)
{
	ft_print_status(philo->data, philo->id, "is sleeping");
	ft_ms_sleep_check(philo->data, philo->data->time_to_sleep);
	ft_print_status(philo->data, philo->id, "is thinking");
	ft_ms_sleep_check(philo->data, 1);
}

/**
 * ENGLISH: The main routine executed by each philosopher thread.
 * It handles the philosopher's lifecycle: taking forks, eating,
 * checking if finished, sleeping, and thinking.
 *
 * SPANISH: La rutina principal ejecutada por cada hilo de filósofo.
 * Maneja el ciclo de vida del filósofo: tomar tenedores, comer,
 * comprobar si ha terminado, dormir y pensar.
 *
 * @param arg Pointer to the philosopher structure. /
 *            Puntero a la estructura del filósofo.
 *
 * @returns NULL. / NULL.
 */
void	*ft_philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (!philo)
		return (NULL);
	pthread_mutex_lock(&philo->meal_mtx);
	philo->last_meal_ms = ft_now_ms();
	pthread_mutex_unlock(&philo->meal_mtx);

	/* Stagger philosophers to reduce initial fork contention.
	   For large N use minimal delays to avoid starvation while still
	   preventing all philosophers from grabbing forks simultaneously. */
	if (philo->data->number_of_philosophers > 100)
	{
		if (philo->id % 2 == 0)
			usleep(1000);
	}
	else
	{
		if (philo->id % 2 == 0)
			ft_ms_sleep(philo->data->time_to_eat / 2);
	}
	while (!philo->data->stop)
	{
		ft_take_forks_and_eat(philo);
		if (ft_check_philo_finished(philo))
			break ;
		ft_sleep_and_think(philo);
	}
	return (NULL);
}
