/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_name_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:31:56 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 20:25:59 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_checker_name_arg(const char *str)
{
	size_t	len;

	if (!str)
	{
		ft_putstr_error("Error 1: Invalid file name.\n");
		return (-1);
	}
	len = ft_strlen(str);
	if (len < 4 || str[len - 4] != '.' || str[len - 3] != 'b'
		|| str[len - 2] != 'e' || str[len - 1] != 'r')
	{
		ft_putstr_error("Error 2: Invalid file extension.\n");
		return (-1);
	}
	return (0);
}
