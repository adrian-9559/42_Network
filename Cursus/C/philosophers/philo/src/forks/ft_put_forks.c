/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:12:08 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 17:57:41 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Philosopher puts down the two forks.
 *
 * SPANISH: El filósofo deja los dos tenedores.
 *
 * @param p Pointer to the philosopher structure. /
 *          Puntero a la estructura del filósofo.
 */
void	ft_put_forks(t_philosopher *p)
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
	pthread_mutex_unlock(&p->data->forks[first]);
	pthread_mutex_unlock(&p->data->forks[second]);
}
