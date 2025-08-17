/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:18:46 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:47:54 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

/*
 * ENGLISH: Skips the current argument in a command string.
 *
 * SPANISH: Omite el argumento actual en una cadena de comando.
 *
 * @param cmd
 *      The command string to process. / La cadena de comando a procesar.
 * @param i
 *      Pointer to the index of the current character in the command string. /
 *      Puntero al índice del carácter actual en la cadena de comando.
 */
void	ft_skip_argument(const char *cmd, int *i)
{
	int		in_quote;
	char	quote;

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
}
