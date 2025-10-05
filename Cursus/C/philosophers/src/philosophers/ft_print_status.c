/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:03:57 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/05 23:33:37 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	ft_print_status(t_data *data, int id, const char *msg)
{
	long	timestamp;

	pthread_mutex_lock(&data->print);
	timestamp = ft_now_ms() - data->start_time;
	if (data->stop && ft_strcmp(msg, "died") != 0)
	{
		pthread_mutex_unlock(&data->print);
		return ;
	}
	/* if someone is dying, mark stop while holding the print mutex so other threads see it before they try to print */
	if (ft_strcmp(msg, "died") == 0)
		data->stop = 1;
	ft_putstr("", 1, 0);
	dprintf(1, "%ld %d %s\n", timestamp, id, msg);
	pthread_mutex_unlock(&data->print);
}
