/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:40:15 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 17:56:22 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Initialize shared resources required by the philosopher threads:
 *  - allocate array of fork mutexes
 *  - initialize each fork mutex
 *  - initialize the print mutex
 *  - set control flags and timestamps
 *
 * SPANISH: Inicializa los recursos compartidos requeridos por los hilos:
 *  - reserva el array de mutex para los tenedores
 *  - inicializa cada mutex de tenedor
 *  - inicializa el mutex de impresión
 *  - establece flags de control y marcas temporales
 *
 * @param data Pointer to the shared t_data structure. /
 *             Puntero a la estructura t_data compartida.
 *
 * @returns 0 on success, 1 on failure (malloc or mutex initialization errors). /
 *          0 en caso de éxito, 1 en caso de fallo (errores de malloc o
 * 			inicialización de mutex).
 */
int	ft_create_thread(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t)
			* data->number_of_philosophers);
	if (!data->forks)
	{
		ft_error(NAME_FT_CREATE_THREAD_C,
			(char *[2]){ERR_MALLOC_PHILOSOPHER, NULL});
		return (1);
	}
	if (ft_init_mutexes(data->forks, (int)data->number_of_philosophers) != 0)
	{
		free(data->forks);
		return (1);
	}
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{
		ft_error(NAME_FT_CREATE_THREAD_C, (char *[2]){ERR_INIT_MUTEX, NULL});
		free(data->forks);
		return (1);
	}
	data->stop = 0;
	data->start_time = ft_now_ms();
	data->death_time = -1;
	return (0);
}
