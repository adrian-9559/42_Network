/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:03:39 by adriescr          #+#    #+#             */
/*   Updated: 2025/12/17 15:55:23 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * ENGLISH: Checks if all command-line arguments are positive integers.
 *
 * SPANISH: Comprueba si todos los argumentos de la línea de comandos son
 * enteros positivos.
 *
 * @param argc The argument count. / El conteo de argumentos.
 * @param argv The argument vector. / El vector de argumentos.
 *
 * @return 0 if all arguments are valid, 1 if any argument is empty,
 *         2 if any argument contains non-digit characters. // 0 si todos los
 *         argumentos son válidos, 1 si algún argumento está vacío,
 *         2 si algún argumento contiene caracteres no numéricos.
 */
static int	ft_checker_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (1);
		while (argv[i][j])
		{
			if (!ft_isdigit(&argv[i][j]))
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		ret;

	if (argc != 5 && argc != 6)
	{
		ft_error(NAME_MAIN_C, (char *[2]){ERR_NUM_ARGS, NULL});
		return (1);
	}
	if (ft_checker_args(argc, argv) != 0)
	{
		ft_error(NAME_MAIN_C, (char *[2]){ERR_INVALID_ARG, NULL});
		return (1);
	}
	data = ft_construct_data(argc, argv);
	if (ft_create_thread(&data) != 0)
		return (1);
	ret = ft_philosophers(&data);
	ft_cleanup_data(&data);
	return (ret);
}
