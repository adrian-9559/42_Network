/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:35:21 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:01:05 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

/*
 * ENGLISH: Generates a pseudo-random number.
 *
 * SPANISH: Genera un número pseudoaleatorio.
 *
 * @param seed   A pointer to the seed value. /
 *               Un puntero al valor de la semilla.
 *
 * @returns The next pseudo-random number. /
 *          El siguiente número pseudoaleatorio.
 */
unsigned int	ft_simple_rand(unsigned int *seed)
{
	*seed = (*seed * 1103515245 + 12345) & 0x7fffffff;
	return (*seed);
}
