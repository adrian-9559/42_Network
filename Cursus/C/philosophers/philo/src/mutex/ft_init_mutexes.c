/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:46:23 by adriescr          #+#    #+#             */
/*   Updated: 2025/12/17 15:03:28 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Initializes an array of mutexes for the mutex.
 *
 * SPANISH: Inicializa un array de mutexes para los tenedores.
 *
 * @param mutex Pointer to the array of mutex to initialize. /
 *              Puntero al array de mutex a inicializar.
 * @param number_of_philosophers The number of philosophers (and mutex). /
 *              El número de filósofos (y mutex).
 *
 * @returns 0 on success, 1 on failure. / 0 en caso de éxito, 1 en caso de fallo.
 */
int	ft_init_mutexes(pthread_mutex_t *mutex, int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		if (pthread_mutex_init(&mutex[i], NULL) != 0)
		{
			ft_error(NAME_FT_INIT_C, (char *[2]){ERR_INIT_MUTEX, NULL});
			return (1);
		}
		i++;
	}
	return (0);
}
