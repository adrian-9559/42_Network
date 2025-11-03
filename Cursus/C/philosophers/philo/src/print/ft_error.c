/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:38:46 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 18:01:39 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Prints an error message to standard error (file descriptor 2).
 * The message includes a general "Error" prefix, the function name,
 * and each string in the provided array 'str'.
 *
 * SPANISH: Imprime un mensaje de error en el error estándar
 * (descriptor de archivo 2). El mensaje incluye un prefijo general
 * "Error", el nombre de la función y cada cadena en el array proporcionado
 * 'str'.
 *
 * @param function The name of the function where the error occurred. /
 *                 El nombre de la función donde ocurrió el error.
 * @param str An array of strings containing specific error messages. /
 *            Un array de cadenas que contiene mensajes de error específicos.
 *
 * @returns The total number of characters printed. /
 *          El número total de caracteres impresos.
 */
long	ft_error(const char *function, char **str)
{
	const char	*name_function;
	long		print;
	int			i;

	name_function = function;
	print = 0;
	print += ft_putstr("Error\n", 2, 1);
	print += ft_putstr((char *)name_function, 2, 1);
	print += ft_putchar('\n', 2);
	i = 0;
	while (str[i])
	{
		print += ft_putstr(str[i], 2, 1);
		i++;
	}
	print += ft_putchar('\n', 2);
	return (print);
}
