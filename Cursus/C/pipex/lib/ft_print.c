/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:24:01 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:49:23 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/*
 * ENGLISH: Prints a string to the standard output.
 *
 * SPANISH: Imprime una cadena en la salida estándar.
 *
 * @param str
 *      The string to print. / La cadena a imprimir.
 *
 * @return {int}
 *      Returns the number of characters printed. / Devuelve el número de 
 *      caracteres impresos.
 */
int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/*
 * ENGLISH: Prints an error string to the standard error output.
 *
 * SPANISH: Imprime una cadena de error en la salida de error estándar.
 *
 * @param str
 *      The error string to print. / La cadena de error a imprimir.
 *
 * @return {int}
 *      Returns the number of characters printed. / Devuelve el número de 
 *      caracteres impresos.
 */
int	ft_print_error_str(char *str)
{
	int	i;

	write(2, "\033[31m", 5);
	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\033[0m", 4);
	return (i);
}
