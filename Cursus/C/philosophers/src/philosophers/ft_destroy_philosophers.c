/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_philosophers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:18:41 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/30 13:05:15 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

int	ft_destroy_philosophers(t_philosopher *philosophers)
{
	const char		*name_function = "(ft_destroy_philosophers.c)";
	int				i;

	if (!philosophers)
		return (0);
	i = 0;
	while (i < philosophers[0].data->number_of_philosophers)
	{
		pthread_mutex_destroy(&philosophers[i].meal_mtx);
		i++;
	}
	free(philosophers);
	return (0);
}
