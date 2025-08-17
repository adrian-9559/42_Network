/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_shell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:31:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:48:08 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

/*
 * ENGLISH: Splits a shell command string into an array of arguments.
 *
 * SPANISH: Divide una cadena de comando de shell en un arreglo de argumentos.
 *
 * @param {const char *} cmd
 *      - The command string to split.
 *      - La cadena de comando a dividir.
 *
 * @returns {char **}
 *      - Returns an array of strings containing the arguments.
 *      - Retorna un arreglo de cadenas que contiene los argumentos.
 */
char	**ft_split_shell(const char *cmd)
{
	int		i;
	int		arg_idx;
	int		argc;
	char	**args;
	char	*arg;

	i = 0;
	arg_idx = 0;
	argc = ft_count_args(cmd);
	args = malloc(sizeof(char *) * (argc + 1));
	if (!args)
		return (NULL);
	arg = ft_get_next_arg(cmd, &i);
	while (arg)
	{
		args[arg_idx++] = arg;
		arg = ft_get_next_arg(cmd, &i);
	}
	args[arg_idx] = NULL;
	return (args);
}
