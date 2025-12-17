/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timeval_to_ms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:44:30 by adriescr          #+#    #+#             */
/*   Updated: 2025/12/17 15:11:25 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Convert a timeval structure to milliseconds.
 *
 * SPANISH: Convierte una estructura timeval a milisegundos.
 *
 * @param tv Pointer to the timeval structure to convert.
 * @return Time in milliseconds as a long.
 */
long	ft_timeval_to_ms(struct timeval *tv)
{
	return (tv->tv_sec * 1000L + tv->tv_usec / 1000L);
}
