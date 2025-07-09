/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_figure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:45:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 23:42:04 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

static int	ft_checker_rectangle(char **map, int rows)
{
	int	i;
	int	len;

	len = ft_strlen(map[0]);
	i = 1;
	while (i < rows)
	{
		if ((int)ft_strlen(map[i]) != len)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_checker_figure(char **map, int rows)
{
	int	cols;

	cols = ft_small_map(map, rows) - 1;
	if (cols < 0)
		return (ft_putstr_error("Error 10.1: Map is too small.\n"), -1);
	if (ft_checker_wall(map, rows, cols) < 0)
		return (ft_putstr_error(
				"Error 10.2: Map is not surrounded by walls.\n"
			), -1);
	if (ft_checker_rectangle(map, rows) < 0)
		return (ft_putstr_error("Error 10.3: Map is not rectangular.\n"), -1);
	return (0);
}
