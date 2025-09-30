/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_forks_and_eat.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 20:05:38 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/30 13:05:06 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	*ft_take_forks_and_eat(t_philosopher *philo)
{
	ft_take_forks(philo);
	ft_start_eating(philo);
	ft_put_forks(philo);
	return (NULL);
}
