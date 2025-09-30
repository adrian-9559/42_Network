/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:22:35 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/30 13:19:15 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

long	ft_putcolor(int fd, int color)
{
	const char	*s;
	long		len;

	if (color == 1)
		s = RED;
	else if (color == 2)
		s = GREEN;
	else if (color == 3)
		s = YELLOW;
	else if (color == 4)
		s = ORANGE;
	else if (color == 5)
		s = BLUE;
	else if (color == 6)
		s = MAGENTA;
	else if (color == 7)
		s = CYAN;
	else if (color == 8)
		s = WHITE;
	else if (color == 9)
		s = RESET;
	else
		return (0);
	len = ft_strlen(s);
	return (ft_putstr(s, fd, color));
}
