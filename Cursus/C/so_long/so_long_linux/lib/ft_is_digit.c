/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:50:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:00:02 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

/*
 * ENGLISH: Checks if a character is a digit.
 *
 * SPANISH: Verifica si un carácter es un dígito.
 *
 * @param c   The character to check. /
 *            El carácter a verificar.
 *
 * @returns 1 if the character is a digit, 0 otherwise. /
 *          1 si el carácter es un dígito, 0 en caso contrario.
 */
int	ft_is_digit(unsigned char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
