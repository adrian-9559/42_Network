/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:11:42 by adriescr          #+#    #+#             */
/*   Updated: 2025/12/15 19:10:38 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Philosopher takes the two forks in a deadlock-free manner.
 *
 * SPANISH: El filósofo toma los dos tenedores de manera libre de interbloqueos.
 *
 * @param p Pointer to the philosopher structure. /
 *          Puntero a la estructura del filósofo.
 */
void	ft_take_forks(t_philosopher *p)
{
	int	first;
	int	second;

	if (p->left_fork_idx < p->right_fork_idx)
	{
		first = p->left_fork_idx;
		second = p->right_fork_idx;
	}
	else
	{
		first = p->right_fork_idx;
		second = p->left_fork_idx;
	}
	pthread_mutex_lock(&p->data->forks[first]);
	ft_print_status(p->data, p->id, "has taken a fork");
	pthread_mutex_lock(&p->data->forks[second]);
	ft_print_status(p->data, p->id, "has taken a fork");
	pthread_mutex_lock(&p->meal_mtx);
	p->last_meal_ms = ft_now_ms();
	pthread_mutex_unlock(&p->meal_mtx);
}
