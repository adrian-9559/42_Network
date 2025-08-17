/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unescape_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:14:08 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 15:02:04 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/*
 * ENGLISH: Unescapes quotes in a command argument.
 *
 * SPANISH: Desescapa las comillas en un argumento de comando.
 *
 * @param arg
 *      The command argument to process. / El argumento de comando a procesar.
 */
void	ft_unescape_quotes(char *arg)
{
	int	i;
	int	j;

	if (!arg)
		return ;
	i = 0;
	j = 0;
	while (arg[i])
	{
		if (arg[i] == '\\' && (arg[i + 1] == '"' || arg[i + 1] == '\''))
			i++;
		arg[j++] = arg[i++];
	}
	arg[j] = '\0';
}
