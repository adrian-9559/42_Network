/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_eating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:13:25 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/29 20:22:23 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

int	ft_start_eating(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->meal_mtx);
	philo->last_meal_ms = ft_now_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mtx);
	ft_print_status(philo->data, philo->id, "is eating");
	ft_ms_sleep(philo->data->time_to_eat);
	return (0);
}
