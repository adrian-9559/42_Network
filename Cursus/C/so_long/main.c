/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:18:36 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:17:43 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * ENGLISH: The main function of the program.
 *
 * SPANISH: La función principal del programa.
 *
 * @param argc  The number of command line arguments.
 *              El número de argumentos de la línea de comandos.
 *
 * @param argv  The command line arguments.
 *              Los argumentos de la línea de comandos.
 *
 * @returns int
 *
 * - 0 on success.
 *   0 en caso de éxito.
 *
 * - -1 if an error occurs.
 *   -1 si ocurre un error.
 */
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
	if (ft_game(argv[1]) < 0)
		return (-1);
	return (0);
}
