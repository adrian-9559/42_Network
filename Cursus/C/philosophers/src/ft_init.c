/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:23:29 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/29 19:24:17 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_init_mutexes(pthread_mutex_t *forks, int number_of_philosophers)
{
	const char	*name_function = "(ft_init_mutexes.c)";
	int			i;

	i = 0;
	while (i < number_of_philosophers)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			ft_error(name_function, (char *[2]){ERR_INIT_MUTEX, NULL});
			return (1);
		}
		i++;
	}
	return (0);
}
