/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:03:57 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/30 13:04:58 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	ft_print_status(t_data *data, int id, const char *msg)
{
	long	timestamp;

	timestamp = ft_now_ms() - data->start_time;
	pthread_mutex_lock(&data->print);
	if (data->stop && ft_strcmp(msg, "died") != 0)
	{
		pthread_mutex_unlock(&data->print);
		return ;
	}
	ft_putstr("", 1, 0);
	dprintf(1, "%ld %d %s\n", timestamp, id, msg);
	pthread_mutex_unlock(&data->print);
}
