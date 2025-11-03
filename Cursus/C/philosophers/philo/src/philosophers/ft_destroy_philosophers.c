/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_philosophers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:18:41 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 17:52:27 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Destroys the array of philosophers, freeing allocated resources.
 *
 * SPANISH: Destruye el array de filósofos, liberando los recursos asignados.
 *
 * @param philosophers Pointer to the array of philosophers to destroy. /
 *                     Puntero al array de filósofos a destruir.
 *
 * @returns 0 on success. / 0 en caso de éxito.
 */
int	ft_destroy_philosophers(t_philosopher *philosophers)
{
	int	i;

	if (!philosophers)
		return (0);
	i = 0;
	while (i < philosophers[0].data->number_of_philosophers)
	{
		pthread_mutex_destroy(&philosophers[i].meal_mtx);
		i++;
	}
	free(philosophers);
	return (0);
}
