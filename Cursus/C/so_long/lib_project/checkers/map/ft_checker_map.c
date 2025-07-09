/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:39:40 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 23:47:35 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_checker_map(const char *filename)
{
	char	**map;
	int		rows;

	rows = ft_get_map_file(filename, &map);
	if (rows < 0 || map == NULL)
		return (ft_putstr_error("Error 9: Could not read the map file.\n"), -1);
	else
	// Show the map for debugging purposes
		ft_show_map(map, rows);
	if (ft_checker_figure(map, rows) < 0)
		return (ft_putstr_error("Error 10: Map has a failure.\n"),
			ft_free_map(map, rows), -1);
	if (ft_checker_requirements(map) < 0)
		return (ft_putstr_error(
				"Error 11: Map does not meet the requirements.\n"
			), ft_free_map(map, rows), -1);
	ft_free_map(map, rows);
	return (0);
}
