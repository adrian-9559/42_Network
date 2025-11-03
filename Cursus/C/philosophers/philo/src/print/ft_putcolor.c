/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:22:35 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 18:02:02 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Outputs the ANSI escape code for the specified color to the
 * given file descriptor.
 *
 * SPANISH: Imprime el código de escape ANSI para el color especificado
 * al descriptor de archivo dado.
 *
 * @param fd The file descriptor to print to. / El descriptor de archivo donde
 * imprimir.
 * @param color The color code (1-8) for text color, or 9 to reset. /
 *              El código de color (1-8) para el color del texto, o 9
 *              para restablecer.
 *
 * @returns The number of characters printed. / El número de caracteres impresos.
 */
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
	len = ft_strlen(s);
	if (len > 0)
		return ((long)write(fd, s, (size_t)len));
	return (0);
}
