/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:34:52 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 17:56:41 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Cleans up the data structure by destroying mutexes and freeing
 * allocated memory.
 *
 * SPANISH: Limpia la estructura de datos destruyendo los mutexes y liberando
 * la memoria asignada.
 *
 * @param data Pointer to the data structure to clean up. /
 *             Puntero a la estructura de datos a limpiar.
 *
 * @returns 0 on success, -1 if data is NULL. / 0 en caso de éxito,
 * 	-1 si data es NULL.
 */
int	ft_cleanup_data(t_data *data)
{
	int	i;

	if (!data)
		return (-1);
	if (data->forks)
	{
		i = 0;
		while (i < data->number_of_philosophers)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
	}
	pthread_mutex_destroy(&data->print);
	return (0);
}
