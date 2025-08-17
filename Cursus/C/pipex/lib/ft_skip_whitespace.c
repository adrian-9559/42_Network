/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_whitespace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:07:48 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:49:46 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/*
 * ENGLISH: Skips whitespace characters in a command string.
 *
 * SPANISH: Omite los caracteres de espacio en blanco en una cadena de comando.
 *
 * @param cmd
 *          The command string to process. /
 *          La cadena de comando a procesar.
 * @param i
 *          A pointer to the current index in the command string. /
 *          Un puntero al índice actual en la cadena de comando.
 */
void	ft_skip_whitespace(const char *cmd, int *i)
{
	while (ft_isspace(cmd[*i]))
		(*i)++;
}
