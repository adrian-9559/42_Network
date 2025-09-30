/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timeval_to_ms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:44:30 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/29 19:45:26 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

long	ft_timeval_to_ms(struct timeval *tv)
{
	return (tv->tv_sec * 1000L + tv->tv_usec / 1000L);
}
