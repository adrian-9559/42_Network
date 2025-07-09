/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:41:03 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 13:22:39 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	ft_putstr(const char *str)
{
	if (!str)
	{
		ft_putstr_error("Error: NULL string\n");
		return (0);
	}
	while (*str)
	{
		if (ft_putchar(*str) == -1)
		{
			ft_putchar('\n');
			return (-1);
		}
		str++;
	}
	return (0);
}
