/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:11:42 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/30 13:16:52 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	ft_take_forks(t_philosopher *p)
{
	int		first;
	int		second;

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
}
