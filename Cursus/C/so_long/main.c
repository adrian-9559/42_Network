/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:18:36 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/10 11:57:15 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (ft_checker_number_args(argc) < 0)
		return (-1);
	if (ft_checker_name_arg(argv[1]) < 0)
		return (-1);
	if (argc > 2 && ft_strcmp(argv[2], "-x") == 0)
		ft_generate(argv[1]);
	else if (ft_checker_file_exists(argv[1]) < 0)
		return (-1);
	if (ft_checker_map(argv[1]) < 0)
		return (-1);
	if (ft_start_game(argv[1]) < 0)
		return (-1);
	return (0);
}
