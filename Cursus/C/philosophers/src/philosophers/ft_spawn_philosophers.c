/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spawn_philosophers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:58:37 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/13 15:51:46 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

int	ft_spawn_philosophers(t_philosopher *philosophers)
{
	int	i;
	int	n;

	if (!philosophers)
		return (1);
	n = philosophers[0].data->number_of_philosophers;
	i = 0;
	while (i < n)
	{
		philosophers[i].last_meal_ms = philosophers[i].data->start_time;
		if (pthread_create(&philosophers[i].thread, NULL,
				&ft_philo_routine, &philosophers[i]) != 0)
		{
			return (1);
		}
		/* small stagger between thread creation to avoid simultaneous contention */
		if (i % 2 == 1)
			usleep(1000);
		i++;
	}
	return (0);
}
