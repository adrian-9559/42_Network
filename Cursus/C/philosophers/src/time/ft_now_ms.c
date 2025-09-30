/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_now_ms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:43:28 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/30 13:18:40 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

long	ft_now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (ft_timeval_to_ms(&tv));
}
