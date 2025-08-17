/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:20:47 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:48:40 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/*
 * ENGLISH: Checks if a character is a whitespace character.
 *
 * SPANISH: Comprueba si un carácter es un carácter de espacio en blanco.
 *
 * @param c
 *      The character to check. / El carácter a comprobar.
 *
 * @return {int}
 *      Returns 1 if the character is a whitespace character, 0 otherwise.
 *      / Devuelve 1 si el carácter es un espacio en blanco, 0 en caso contrario.
 */
int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}
