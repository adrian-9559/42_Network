/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:09:01 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/05 17:03:57 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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

int	ft_philosophers(t_data *data)
{
	const char		*name_function = "(ft_philosophers.c)";
	t_philosopher	*philosophers;
	pthread_t		monitor_thread;

	philosophers = ft_create_philosophers(data);
	if (!philosophers)
		return (1);
	if (ft_spawn_philosophers(philosophers) != 0)
	{
		ft_error(name_function, (char *[2]){"Failed to spawn threads", NULL});
		ft_destroy_philosophers(philosophers);
		return (1);
	}
	if (ft_start_monitor_thread(&monitor_thread, philosophers,
			name_function) != 0)
	{
		ft_destroy_philosophers(philosophers);
		return (1);
	}
	ft_join_philosopher_threads(philosophers, data->number_of_philosophers);
	pthread_join(monitor_thread, NULL);
	ft_destroy_philosophers(philosophers);
	return (0);
}
