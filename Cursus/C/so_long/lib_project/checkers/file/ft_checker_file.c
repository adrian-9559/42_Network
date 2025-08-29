/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:54:27 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/29 21:53:15 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_checker_file_exists(const char *filename)
{
	int	file;

	file = open(filename, O_RDONLY);
	if (file >= 0)
	{
		close(file);
		return (0);
	}
	else
	{
		ft_putstr_error("Error\n Function: ft_checker_file_exists\n	"
			"	File does not exist.\n");
		return (-1);
	}
}
