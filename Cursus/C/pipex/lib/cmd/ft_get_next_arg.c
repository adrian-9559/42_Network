/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:32:55 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:47:31 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

/*
 * ENGLISH: Retrieves the next argument from a command string.
 *
 * - Skips whitespace and extracts the next argument until a space or 
 * 	end of string.
 * 
 * - Handles quoted strings and unescapes quotes.
 * 
 * - Returns a dynamically allocated string containing the argument.
 *
 * SPANISH: Recupera el siguiente argumento de una cadena de comando.
 *
 * - Omite los espacios en blanco y extrae el siguiente argumento hasta 
 * un espacio o el final de la cadena.
 * 
 * - Maneja cadenas entre comillas y desescapa las comillas.
 * 
 * - Devuelve una cadena asignada dinámicamente que contiene el argumento.
 *
 * @param cmd The command string to parse. / La cadena de comando a analizar.
 * @param i 
 * 		Pointer to the current index in the command string. / 
 * 		Puntero al índice actual en la cadena de comando.
 * @return 
 * 		A dynamically allocated string containing the next argument, 
 * 		or NULL if no more arguments are found. / Devuelve una cadena
 * 		asignada dinámicamente que contiene el siguiente argumento, o NULL
 * 		si no se encuentran más argumentos.
 */
char	*ft_get_next_arg(const char *cmd, int *i)
{
	int		len;
	char	*arg;

	while (ft_isspace(cmd[*i]))
		(*i)++;
	if (!cmd[*i])
		return (NULL);
	len = ft_arg_len(cmd, i);
	arg = malloc(len + 1);
	if (!arg)
		return (NULL);
	ft_strncpy(arg, cmd + *i - len, len);
	arg[len] = '\0';
	ft_trim_quotes(arg);
	ft_unescape_quotes(arg);
	return (arg);
}
