/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:20:04 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/30 13:18:29 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

long	ft_putstr(const char *str, int fd, int color)
{
	int		i;
	long	len_print;

	i = 0;
	len_print = 0;
	if (color != 0 && color > 0 && color < 9)
		len_print += ft_putcolor(fd, color);
	while (str[i] != '\0')
	{
		len_print += ft_putchar(str[i], fd);
		i++;
	}
	if (color != 0 && color > 0 && color < 9)
		len_print += ft_putcolor(fd, 9);
	return (len_print);
}
