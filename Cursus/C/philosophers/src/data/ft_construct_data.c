/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:38:09 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/29 19:38:41 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

t_data	ft_construct_data(int argc, char **argv, char **envp)
{
	const char		*name_function = "(ft_construct_data.c)";
	t_data			data;

	data.number_of_philosophers = ft_atoi(argv[1]);
	if (data.number_of_philosophers < 1)
		ft_error(name_function, (char *[2]){ERR_NUM_PHILOSOPHERS, NULL});
	data.time_to_die = ft_atoi(argv[2]);
	if (data.time_to_die < 0)
		ft_error(name_function, (char *[2]){ERR_TIME_TO_DIE, NULL});
	data.time_to_eat = ft_atoi(argv[3]);
	if (data.time_to_eat < 0)
		ft_error(name_function, (char *[2]){ERR_TIME_TO_EAT, NULL});
	data.time_to_sleep = ft_atoi(argv[4]);
	if (data.time_to_sleep < 0)
		ft_error(name_function, (char *[2]){ERR_TIME_TO_SLEEP, NULL});
	if (argc == 6)
		data.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		data.number_of_times_each_philosopher_must_eat = -1;
	return (data);
}
