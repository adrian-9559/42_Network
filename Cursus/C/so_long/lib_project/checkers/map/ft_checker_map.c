/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:39:40 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 20:25:48 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_checker_map(const char *filename)
{
	char	**map;
	int		rows;

	rows = ft_get_map_file(filename, &map);
	if (rows < 0)
		return (ft_putstr_error("Error 9: Could not read the map file.\n"), -1);
	else
		ft_show_map(map, rows);
	return (0);
}
