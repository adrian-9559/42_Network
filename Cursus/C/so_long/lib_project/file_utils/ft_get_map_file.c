/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:52:13 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/29 21:44:23 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

static int	ft_append_line(char ***map, char *line, int rows)
{
	char	**new_map;

	new_map = ft_realloc_map(*map, rows + 1);
	if (!new_map)
	{
		free(line);
		ft_free_map(*map, rows);
		return (0);
	}
	*map = new_map;
	(*map)[rows] = line;
	return (1);
}

int	ft_get_map_file(const char *filename, char ***map)
{
	int		fd;
	char	*line;
	int		rows;

	fd = ft_open_file_read(filename);
	if (fd < 0)
		return (-1);
	rows = 0;
	*map = NULL;
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		if (!ft_append_line(map, line, rows))
			return (-1);
		rows++;
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (rows);
}
