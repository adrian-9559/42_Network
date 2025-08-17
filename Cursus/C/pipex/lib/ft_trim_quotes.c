/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:29:33 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 15:01:58 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/* ENGLISH: Trims quotes and spaces from the beginning and end of a string.
 *
 * SPANISH: Elimina las comillas y los espacios del principio y del final de 
 * una cadena.
 *
 * @param {char *} arg
 *      The string to trim. / La cadena de la que se eliminarán los caracteres.
 */
void	ft_trim_quotes(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (len >= 2 && ((arg[0] == '"' && arg[len - 1] == '"')
			|| (arg[0] == '\'' && arg[len - 1] == '\'')))
	{
		ft_memmove(arg, arg + 1, len - 2);
		arg[len - 2] = '\0';
	}
}
