/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:03:57 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/05 16:30:33 by adriescr         ###   ########.fr       */
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
 * @param id The ID of the philosopher. / El ID del filósofo.
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
		/* suppress non-death messages that occur at or after the recorded
		   death timestamp to avoid racey outputs when stdout is redirected */
		if (timestamp >= data->death_time)
		{
			pthread_mutex_unlock(&data->print);
			return ;
		}
	}
	if (ft_strcmp(msg, "died") == 0)
		data->stop = 1;
	/* Compose the output and write with write(1,...) to avoid stdio buffering
	   interactions with the monitor. */
	{
		char buf[128];
		int pos = 0;
		long tmp = timestamp;
		char numbuf[32];
		int npos = 0;
		int pid = id;

		if (tmp == 0)
			numbuf[npos++] = '0';
		while (tmp > 0 && npos < (int)sizeof(numbuf))
		{
			numbuf[npos++] = (char)('0' + (tmp % 10));
			tmp /= 10;
		}
		while (npos > 0)
			buf[pos++] = numbuf[--npos];
		buf[pos++] = ' ';
		if (pid == 0)
			buf[pos++] = '0';
		else
		{
			int idtmp = pid;
			char idbuf[8];
			int ipos = 0;
			while (idtmp > 0 && ipos < (int)sizeof(idbuf))
			{
				idbuf[ipos++] = (char)('0' + (idtmp % 10));
				idtmp /= 10;
			}
			while (ipos > 0)
				buf[pos++] = idbuf[--ipos];
		}
		buf[pos++] = ' ';
		{
			const char *s = msg;
			while (*s && pos < (int)sizeof(buf) - 2)
				buf[pos++] = *s++;
		}
		buf[pos++] = '\n';
		(void)write(1, buf, pos);
	}
	pthread_mutex_unlock(&data->print);
}
