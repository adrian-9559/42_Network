/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:12:08 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/30 13:16:16 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	ft_put_forks(t_philosopher *p)
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
	pthread_mutex_unlock(&p->data->forks[first]);
	pthread_mutex_unlock(&p->data->forks[second]);
}
