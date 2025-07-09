/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:37:54 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 18:40:31 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

int	ft_generate(const char *filename)
{
	int	fd;

	fd = ft_open_file_read(filename);
	if (fd < 0)
		if (ft_generate_file(filename) < 0)
			return (ft_putstr_error("Error 4: Could not create file.\n"), -1);
	close(fd);
	if (ft_generate_map(filename) > 0)
		return (ft_putstr_error("Error 1: Error generating map.\n"), -1);
	return (0);
}
