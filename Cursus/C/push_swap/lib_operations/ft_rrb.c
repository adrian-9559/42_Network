/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:22:15 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/08 20:53:46 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_rrb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	last = *stack_b;
	while (last->next->next)
		last = last->next;
	*stack_b = last->next;
	last->next = NULL;
	(*stack_b)->next = temp;
	ft_putstr("rrb\n");
}
