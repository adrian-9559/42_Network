/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:45:00 by automated         #+#    #+#             */
/*   Updated: 2025/10/05 23:33:37 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static int	ft_check_philo(t_data *data, t_philosopher *philos, int i,
		int *all_finished)
{
	long	now;

	/* Lock the philosopher meal mutex first to avoid deadlock with threads that
	   lock meal_mtx then print. Then, if a death is detected, lock the print
	   mutex to serialize the output. */
	pthread_mutex_lock(&philos[i].meal_mtx);
	now = ft_now_ms();
	if ((now - philos[i].last_meal_ms) > data->time_to_die)
	{
		/* Use centralized print function to mark stop and print atomically */
		pthread_mutex_unlock(&philos[i].meal_mtx);
		ft_print_status(data, philos[i].id, "died");
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
