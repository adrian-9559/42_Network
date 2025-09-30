/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:38:46 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/29 19:02:25 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

long	ft_error(const char *function, char **str)
{
	const char	*name_function;
	long		print;
	int			i;

	name_function = function;
	print = 0;
	print += ft_putstr("Error\n", 2, 1);
	print += ft_putstr((char *)name_function, 2, 1);
	print += ft_putchar('\n', 2);
	i = 0;
	while (str[i])
	{
		print += ft_putstr(str[i], 2, 1);
		i++;
	}
	print += ft_putchar('\n', 2);
	return (print);
}
