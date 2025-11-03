/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_now_ms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:43:28 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 17:58:29 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH:
 *   Return the current time in milliseconds. Uses gettimeofday() and
 *   converts the resulting timeval to milliseconds via ft_timeval_to_ms().
 *
 * SPANISH:
 *   Devuelve el tiempo actual en milisegundos. Usa gettimeofday() y
 *   convierte el timeval obtenido a milisegundos con ft_timeval_to_ms().
 *
 * @return Current time in milliseconds as a long.
 */
long	ft_now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (ft_timeval_to_ms(&tv));
}
