/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_map_empty.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:21:35 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 20:25:44 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_checker_map_empty_rows(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\0')
		{
			j = 0;
			while (map[j])
			{
				free(map[j]);
				j++;
			}
			free(map);
			return (-1);
		}
		i++;
	}
	return (0);
}
