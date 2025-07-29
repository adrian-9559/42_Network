/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:42:14 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/29 16:11:29 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	ft_putchar_error(char c)
{
	const char	*red;
	const char	*reset;

	red = "\033[31m";
	reset = "\033[0m";
	if (write(2, red, 5) == -1)
		return (-1);
	if (write(2, &c, 1) == -1)
		return (-1);
	if (write(2, reset, 4) == -1)
		return (-1);
	return (0);
}
