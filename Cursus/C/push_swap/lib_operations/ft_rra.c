/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:21:20 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/08 20:53:41 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	last = *stack_a;
	while (last->next->next)
		last = last->next;
	*stack_a = last->next;
	last->next = NULL;
	(*stack_a)->next = temp;
	ft_putstr("rra\n");
}
