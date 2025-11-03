/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:23:29 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 18:02:31 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

/**
 * ENGLISH: Initializes mutexes for the forks.
 *
 * SPANISH: Inicializa los mutex para los tenedores.
 *
 * @param forks Array of mutexes representing the forks. /
 *              Array de mutex que representan los tenedores.
 * @param number_of_philosophers The number of philosophers (and forks). /
 *                                El número de filósofos (y tenedores).
 *
 * @returns 0 on success, 1 on failure. / 0 en caso de éxito, 1 en caso de fallo.
 */
int	ft_init_mutexes(pthread_mutex_t *forks, int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			ft_error(NAME_FT_INIT_C, (char *[2]){ERR_INIT_MUTEX, NULL});
			return (1);
		}
		i++;
	}
	return (0);
}
