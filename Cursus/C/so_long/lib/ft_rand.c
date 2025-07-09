/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:35:21 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 14:57:05 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

unsigned int	ft_simple_rand(unsigned int *seed)
{
	*seed = (*seed * 1103515245 + 12345) & 0x7fffffff;
	return (*seed);
}
