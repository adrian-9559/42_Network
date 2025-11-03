/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:20:04 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 17:59:04 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Outputs the string 'str' to the file descriptor 'fd'.
 * If 'color' is non-zero, it sets the text color before printing
 * and resets it afterward.
 *
 * SPANISH: Imprime la cadena 'str' al descriptor de archivo 'fd'.
 * Si 'color' es distinto de cero, establece el color del texto antes
 * de imprimir y lo restablece después.
 *
 * @param str The string to print. / La cadena a imprimir.
 * @param fd The file descriptor to print to. / El descriptor de archivo
 * 				donde imprimir.
 * @param color The color code (1-8) for text color, or 0 for no color. /
 *              El código de color (1-8) para el color del texto, o
 * 				0 para sin color.
 *
 * @returns The total number of characters printed. /
 *          El número total de caracteres impresos.
 */
long	ft_putstr(const char *str, int fd, int color)
{
	int		i;
	long	len_print;

	i = 0;
	len_print = 0;
	if (color != 0 && color > 0 && color < 9)
		len_print += ft_putcolor(fd, color);
	while (str[i] != '\0')
	{
		len_print += ft_putchar(str[i], fd);
		i++;
	}
	if (color != 0 && color > 0 && color < 9)
		len_print += ft_putcolor(fd, 9);
	return (len_print);
}
