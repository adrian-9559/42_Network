/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philosophers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:14:41 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/29 20:24:46 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

t_philosopher	*ft_create_philosophers(t_data *data)
{
	const char		*name_function = "(ft_create_philosophers.c)";
	t_philosopher	*philosophers;
	int				i;

	philosophers = malloc(sizeof(t_philosopher) * data->number_of_philosophers);
	if (!philosophers)
	{
		ft_error(name_function, (char *[2]){ERR_MALLOC_PHILOSOPHER, NULL});
		return (NULL);
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		philosophers[i].id = i + 1;
		philosophers[i].meals_eaten = 0;
		philosophers[i].last_meal_ms = 0;
		philosophers[i].left_fork_idx = i;
		philosophers[i].right_fork_idx = (i + 1) % data->number_of_philosophers;
		pthread_mutex_init(&philosophers[i].meal_mtx, NULL);
		philosophers[i].finished = 0;
		philosophers[i].data = data;
		i++;
	}
	return (philosophers);
}
