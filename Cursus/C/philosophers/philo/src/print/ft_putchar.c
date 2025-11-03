/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:18:51 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 17:59:21 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Outputs the character 'c' to the file descriptor 'fd'.
 *
 * SPANISH: Imprime el carácter 'c' al descriptor de archivo 'fd'.
 *
 * @param c The character to print. / El carácter a imprimir.
 * @param fd The file descriptor to print to. /
 * 			El descriptor de archivo donde imprimir.
 *
 * @returns The number of characters printed (1). /
 * 			El número de caracteres impresos (1).
 */
long	ft_putchar(char c, int fd)
{
	return ((long)write(fd, &c, 1));
}
