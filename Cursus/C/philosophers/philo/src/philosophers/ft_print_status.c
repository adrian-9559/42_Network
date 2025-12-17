/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:03:57 by adriescr          #+#    #+#             */
/*   Updated: 2025/12/17 18:01:22 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Prints the current status of a philosopher in a thread-safe manner.
 *
 * SPANISH: Imprime el estado actual de un filósofo de manera segura para
 * hilos.
 *
 * @param data Pointer to the global data structure. / El puntero a la
 *             estructura de datos global.
 * @param msg The status message to print. / El mensaje de estado a imprimir.
 */
void	ft_print_status(t_data *data, int id, const char *msg)
{
	long	timestamp;

	pthread_mutex_lock(&data->print);
	timestamp = ft_now_ms() - data->start_time;
	if (data->stop && ft_strcmp(msg, "died") != 0)
	{
		pthread_mutex_unlock(&data->print);
		return ;
	}
	if (data->death_time >= 0 && ft_strcmp(msg, "died") != 0)
	{
		if (timestamp >= data->death_time)
		{
			pthread_mutex_unlock(&data->print);
			return ;
		}
	}
	if (ft_strcmp(msg, "died") == 0)
		data->stop = 1;
	printf("%ld %d %s\n", timestamp, id, msg);
	pthread_mutex_unlock(&data->print);
}
