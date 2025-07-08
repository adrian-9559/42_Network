/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:17:30 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/08 20:54:07 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	t_stack	*temp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	ft_putstr("sa\n");
}
