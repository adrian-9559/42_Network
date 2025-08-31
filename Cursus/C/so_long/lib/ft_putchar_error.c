/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:42:14 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:00:25 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

/*
 * ENGLISH: Outputs a character to the standard error output.
 *
 * SPANISH: Envía un carácter a la salida de error estándar.
 *
 * @param c   The character to output. /
 *            El carácter a enviar.
 *
 * @returns 0 on success, -1 on failure. /
 *          0 en caso de éxito, -1 en caso de error.
 */
int	ft_putchar_error(char c)
{
	const char	*red;
	const char	*reset;

	red = "\033[31m";
	reset = "\033[0m";
	if (write(2, red, 5) == -1)
		return (-1);
	if (write(2, &c, 1) == -1)
		return (-1);
	if (write(2, reset, 4) == -1)
		return (-1);
	return (0);
}
