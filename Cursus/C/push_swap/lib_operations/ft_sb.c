/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:17:58 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/08 20:54:10 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_sb(t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	ft_putstr("sb\n");
}
