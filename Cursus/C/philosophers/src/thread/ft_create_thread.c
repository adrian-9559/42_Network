/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:40:15 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/05 17:44:30 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

int	ft_create_thread(t_data *data)
{
	const char	*name_function = "(ft_create_thread)";

	data->forks = malloc(sizeof(pthread_mutex_t)
			* data->number_of_philosophers);
	if (!data->forks)
	{
		ft_error(name_function, (char *[2]){ERR_MALLOC_PHILOSOPHER, NULL});
		return (1);
	}
	if (ft_init_mutexes(data->forks, (int)data->number_of_philosophers) != 0)
	{
		free(data->forks);
		return (1);
	}
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{
		ft_error(name_function, (char *[2]){ERR_INIT_MUTEX, NULL});
		free(data->forks);
		return (1);
	}
	data->stop = 0;
	data->start_time = ft_now_ms();
	return (0);
}
