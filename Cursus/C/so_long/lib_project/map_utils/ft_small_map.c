/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:57:52 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 21:04:37 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

int	ft_small_map(char **map, int rows)
{
	int	cols;

	cols = ft_strlen(map[0]);
	if ((cols <= 3 && rows <= 5) || (cols <= 5 && rows <= 3))
		return (-1);
	return (cols);
}
