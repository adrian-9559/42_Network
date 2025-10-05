/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:06:45 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/05 17:13:51 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

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

static void	ft_sleep_and_think(t_philosopher *philo)
{
	ft_print_status(philo->data, philo->id, "is sleeping");
	ft_ms_sleep_check(philo->data, philo->data->time_to_sleep);
	ft_print_status(philo->data, philo->id, "is thinking");
	ft_ms_sleep_check(philo->data, 1);
}

void	*ft_philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (!philo)
		return (NULL);
	/* stagger to reduce contention on forks for even philosophers; use half of time_to_eat */
	if (philo->id % 2 == 0)
		ft_ms_sleep(philo->data->time_to_eat / 2);
	while (!philo->data->stop)
	{
		ft_take_forks_and_eat(philo);
		if (ft_check_philo_finished(philo))
			break ;
		ft_sleep_and_think(philo);
	}
	return (NULL);
}
