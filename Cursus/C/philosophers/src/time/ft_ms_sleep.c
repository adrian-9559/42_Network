/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:42:07 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/30 13:18:01 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	ft_ms_sleep(long ms)
{
	long	start;

	start = ft_now_ms();
	while ((ft_now_ms() - start) < ms)
		usleep(500);
}

/* Sleep but return early if data->stop is set to reduce prints after death */
void	ft_ms_sleep_check(t_data *data, long ms)
{
	long start;

	start = ft_now_ms();
	while ((ft_now_ms() - start) < ms)
	{
		if (data && data->stop)
			break ;
		usleep(200);
	}
}
