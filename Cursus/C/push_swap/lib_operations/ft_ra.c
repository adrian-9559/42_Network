/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:19:07 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/08 20:53:25 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	last->next = temp;
	ft_putstr("ra\n");
}
