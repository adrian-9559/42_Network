/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:38:09 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 17:57:19 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Constructs the simulation data from command-line arguments.
 *
 * SPANISH: Construye los datos de la simulación a partir de los argumentos
 * de la línea de comandos.
 *
 * @param argc The number of command-line arguments. /
 * 			El número de argumentos de la línea de comandos.
 * @param argv The array of command-line argument strings. /
 *             El array de cadenas de argumentos de la línea de comandos.
 * @param envp The array of environment variable strings. /
 *             El array de cadenas de variables de entorno.
 *
 * @returns A t_data structure populated with the simulation parameters. /
 *          Una estructura t_data poblada con los parámetros de la simulación.
 */
t_data	ft_construct_data(int argc, char **argv, char **envp)
{
	t_data	data;

	data.number_of_philosophers = ft_atoi(argv[1]);
	if (data.number_of_philosophers < 1)
		ft_error(NAME_FT_CONSTRUCT_DATA_C,
			(char *[2]){ERR_NUM_PHILOSOPHERS, NULL});
	data.time_to_die = ft_atoi(argv[2]);
	if (data.time_to_die < 0)
		ft_error(NAME_FT_CONSTRUCT_DATA_C, (char *[2]){ERR_TIME_TO_DIE, NULL});
	data.time_to_eat = ft_atoi(argv[3]);
	if (data.time_to_eat < 0)
		ft_error(NAME_FT_CONSTRUCT_DATA_C, (char *[2]){ERR_TIME_TO_EAT, NULL});
	data.time_to_sleep = ft_atoi(argv[4]);
	if (data.time_to_sleep < 0)
		ft_error(NAME_FT_CONSTRUCT_DATA_C,
			(char *[2]){ERR_TIME_TO_SLEEP, NULL});
	if (argc == 6)
		data.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		data.number_of_times_each_philosopher_must_eat = -1;
	return (data);
}
