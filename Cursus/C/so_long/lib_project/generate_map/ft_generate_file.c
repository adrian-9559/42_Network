/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:04:22 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 18:39:24 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

int	ft_generate_file(const char *filename)
{
	int	file;

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!file)
		return (-1);
	ft_putstr("\033[0;32mMap file generated successfully.\033[0m\n");
	return (file);
}
