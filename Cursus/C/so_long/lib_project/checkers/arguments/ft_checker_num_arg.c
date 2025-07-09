/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_num_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:35:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 20:26:02 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_checker_number_args(int argc)
{
	if (argc < 2)
	{
		ft_putstr_error("Error 0: Invalid number of arguments.\n");
		return (-1);
	}
	return (0);
}
