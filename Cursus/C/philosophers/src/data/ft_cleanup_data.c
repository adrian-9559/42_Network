/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:34:52 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/05 17:45:41 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

int	ft_cleanup_data(t_data *data)
{
	int	i;

	if (!data)
		return (-1);
	if (data->forks)
	{
		i = 0;
		while (i < data->number_of_philosophers)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
	}
	pthread_mutex_destroy(&data->print);
	// eat_cond and eat_mtx removed from t_data; no need to destroy them
	
	return (0);
}
