/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:26:57 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:47:01 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

/*
 * ENGLISH: Calculates the length of an argument in a command string.
 *
 * SPANISH: Calcula la longitud de un argumento en una cadena de comando.
 *
 * @param {const char *} cmd
 *      - The command string to analyze.
 *      - La cadena de comando a analizar.
 * @param {int *} i
 *      - Pointer to the current index in the command string.
 *      - Puntero al índice actual en la cadena de comando.
 *
 * @returns {int}
 *      - Returns the length of the argument found at the current index.
 *      - Retorna la longitud del argumento encontrado en el índice actual.
 */
int	ft_arg_len(const char *cmd, int *i)
{
	int		start;
	int		in_quote;
	char	quote;

	start = *i;
	in_quote = 0;
	quote = 0;
	while (cmd[*i])
	{
		if (!in_quote && (cmd[*i] == '\'' || cmd[*i] == '"'))
		{
			in_quote = 1;
			quote = cmd[(*i)++];
		}
		else if (in_quote && cmd[*i] == quote)
		{
			in_quote = 0;
			(*i)++;
		}
		else if (!in_quote && ft_isspace(cmd[*i]))
			break ;
		else
			(*i)++;
	}
	return (*i - start);
}
