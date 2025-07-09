/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:00:59 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 22:46:18 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_checker_wall(char **map, int rows, int cols)
{
	int	j;

	j = 0;
	while (j < cols)
	{
		if (map[0][j] != '1' || map[rows - 1][j] != '1')
			return (-1);
		j++;
	}
	j = 0;
	while (j < rows)
	{
		if (map[j][0] != '1' || map[j][cols - 1] != '1')
			return (-1);
		j++;
	}
	return (0);
}
