/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_file_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:11:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 18:36:00 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

int	ft_save_map_to_file(const char *filename, char **map, int rows)
{
	int		fd;
	int		i;
	int		len;
	int		written;

	fd = ft_open_file_write(filename);
	if (fd < 0)
		return (ft_putstr_error("Error 8.1: Error opening file\n"), -1);
	i = 0;
	while (i < rows)
	{
		len = 0;
		while (map[i][len])
			len++;
		written = write(fd, map[i], len);
		if (written != len)
		{
			close(fd);
			return (ft_putstr_error("Error 8.2: Error writing to file\n"), -1);
		}
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
	return (0);
}
