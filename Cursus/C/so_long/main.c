/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:18:36 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/10 03:43:31 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		rows;

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
	rows = ft_get_map_file(argv[1], &map);
	if (rows < 0)
		return (ft_putstr_error("Error 12: Could not read the map file.\n"), -1);
	ft_free_map(map, rows);
	return (0);
}
