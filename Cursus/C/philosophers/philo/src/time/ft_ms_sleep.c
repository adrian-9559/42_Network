/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:42:07 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 17:58:13 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH:
 *   Sleep for approximately `ms` milliseconds. Implements a short-loop wait
 *   that calls `usleep` in small intervals to improve timing accuracy and to
 *   avoid a single long blocking sleep.
 *   Note: this function does NOT check any shared stop flag; use
 *   `ft_ms_sleep_check` when you need an interruptible sleep.
 *
 * SPANISH:
 *   Duerme aproximadamente `ms` milisegundos. Implementa un bucle con breves
 *   llamadas a `usleep` para mejorar la precisión del tiempo y evitar un único
 *   bloqueo largo.
 *   Nota: esta función NO comprueba ninguna bandera de parada compartida; use
 *   `ft_ms_sleep_check` si necesita un sleep interrumpible.
 *
 * @param ms  Milliseconds to sleep.
 */
void	ft_ms_sleep(long ms)
{
	long	start;

	start = ft_now_ms();
	while ((ft_now_ms() - start) < ms)
		usleep(500);
}

/**
 * ENGLISH:
 *   Sleep for approximately `ms` milliseconds, checking periodically if the
 *   `stop` flag in `data` has been set. If `data->stop` is set, the sleep
 *   will exit early.
 *
 * SPANISH:
 *   Duerme aproximadamente `ms` milisegundos, comprobando periódicamente si
 *   la bandera `stop` en `data` ha sido establecida. Si `data->stop` está
 *   establecido, el sleep terminará antes de tiempo.
 *
 * @param data  Pointer to the shared data structure containing the stop flag.
 * @param ms    Milliseconds to sleep.
 */
void	ft_ms_sleep_check(t_data *data, long ms)
{
	long	start;

	start = ft_now_ms();
	while ((ft_now_ms() - start) < ms)
	{
		if (data && data->stop)
			break ;
		usleep(200);
	}
}
