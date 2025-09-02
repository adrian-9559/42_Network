/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_requirements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:09:53 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/02 16:22:48 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

/*
 * ENGLISH: Checks if the map meets the requirements.
 *
 * SPANISH: Verifica si el mapa cumple con los requisitos.
 *
 * @param map   The map to check. /
 *              El mapa a verificar.
 *
 * @returns int
 *
 * - Returns 0 if the map meets the requirements.
 *   Devuelve 0 si el mapa cumple con los requisitos.
 *
 * - Returns -1 otherwise.
 *   Devuelve -1 en caso contrario.
 */
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
		while (map[conts[0]][conts[1]] && map[conts[0]][conts[1] + 1])
		{
			if (!ft_strchr("01CEP", map[conts[0]][conts[1]]))
				return (-1);
			
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
