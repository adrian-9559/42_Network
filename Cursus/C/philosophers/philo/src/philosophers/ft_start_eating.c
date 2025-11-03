/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_eating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:13:25 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 17:52:13 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Updates the philosopher's last meal time and meals eaten count,
 * then simulates the eating action with a sleep.
 *
 * SPANISH: Actualiza el tiempo de la última comida del filósofo y el conteo
 * de comidas ingeridas, luego simula la acción de comer con una pausa.
 *
 * @param philo Pointer to the philosopher structure. /
 *              Puntero a la estructura del filósofo.
 *
 * @returns 0 on success. / 0 en caso de éxito.
 */
int	ft_start_eating(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->meal_mtx);
	philo->last_meal_ms = ft_now_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mtx);
	if (philo->data->stop)
		return (0);
	ft_print_status(philo->data, philo->id, "is eating");
	ft_ms_sleep_check(philo->data, philo->data->time_to_eat);
	return (0);
}
