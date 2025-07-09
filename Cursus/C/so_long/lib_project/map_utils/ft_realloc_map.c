/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:50:45 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 20:13:56 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

char	**ft_realloc_map(char **map, int new_size)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (new_size + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < new_size - 1 && map[i])
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = NULL;
	free(map);
	return (new_map);
}
