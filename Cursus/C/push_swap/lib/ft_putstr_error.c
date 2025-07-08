/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:41:33 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/08 19:43:53 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	ft_putstr_error(const char *str)
{
	if (!str)
	{
		if (ft_putstr_error("Error: NULL string\n") == -1)
			return (-1);
		return (0);
	}
	while (*str)
	{
		if (ft_putchar_error(*str) == -1)
		{
			ft_putchar_error('\n');
			return (-1);
		}
		str++;
	}
	return (0);
}
