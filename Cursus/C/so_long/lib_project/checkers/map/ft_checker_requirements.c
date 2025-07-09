/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_requirements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:09:53 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 23:41:28 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_checker_requirements(char **map)
{
	int	conts[2];
	int	requirements[3];

	requirements[0] = 0;
	requirements[1] = 0;
	requirements[2] = 0;
	conts[0] = 0;
	while (map[conts[0]])
	{
		conts[1] = 0;
		while (map[conts[0]][conts[1]])
		{
			if (map[conts[0]][conts[1]] == 'C')
				requirements[0]++;
			else if (map[conts[0]][conts[1]] == 'E')
				requirements[1]++;
			else if (map[conts[0]][conts[1]] == 'P')
				requirements[2]++;
			conts[1]++;
		}
		conts[0]++;
	}
	if (requirements[0] < 1 || requirements[1] != 1 || requirements[2] != 1)
		return (-1);
	return (0);
}
