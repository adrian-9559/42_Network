/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_num_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:35:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/29 21:55:09 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_checker_number_args(int argc)
{
	if (argc < 2)
	{
		ft_putstr_error("Error\n Function: ft_checker_number_args\n"
			"	Invalid number of arguments.\n");
		return (-1);
	}
	return (0);
}
