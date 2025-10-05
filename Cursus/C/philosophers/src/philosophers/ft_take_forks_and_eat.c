/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_forks_and_eat.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:05:38 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/03 03:19:35 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	*ft_take_forks_and_eat(t_philosopher *philo)
{
	if (philo->data->number_of_philosophers == 1)
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork_idx]);
		ft_print_status(philo->data, philo->id, "has taken a fork");
		ft_ms_sleep_check(philo->data, philo->data->time_to_die);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork_idx]);
		return (NULL);
	}
	ft_take_forks(philo);
	ft_start_eating(philo);
	ft_put_forks(philo);
	return (NULL);
}
