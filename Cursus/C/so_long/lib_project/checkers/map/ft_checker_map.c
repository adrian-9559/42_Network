/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:39:40 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/29 21:54:24 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_checker_map(const char *filename)
{
	char	**map;
	int		rows;

	rows = ft_get_map_file(filename, &map);
	if (rows < 0 || map == NULL)
		return (ft_putstr_error("Error\n Function: ft_checker_map\n"
				" Could not read the map file.\n"), -1);
	if (ft_checker_figure(map, rows) < 0)
		return (ft_free_map(map, rows), -1);
	if (ft_checker_requirements(map) < 0)
		return (ft_putstr_error(
				"Error\n Function: ft_checker_map\n"
				" Map does not meet the requirements.\n"
			), ft_free_map(map, rows), -1);
	if (ft_checker_posible_complete(map, rows) < 0)
		return (ft_free_map(map, rows), -1);
	ft_free_map(map, rows);
	return (0);
}
