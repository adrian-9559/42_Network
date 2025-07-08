/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:28:47 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/08 22:34:21 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	push_value_to_b(t_stack **a, t_stack **b, int value)
{
	t_stack	*tmp;
	int		stack_size;
	int		index;
	int		rot_count;

	stack_size = ft_stack_size(*a);
	tmp = *a;
	index = 0;
	while (tmp)
	{
		if (tmp->value == value)
			break ;
		tmp = tmp->next;
		index++;
	}
	if (!tmp)
		return ;
	if (index <= stack_size / 2)
	{
		rot_count = index;
		while (rot_count-- > 0)
			ft_ra(a);
	}
	else
	{
		rot_count = stack_size - index;
		while (rot_count-- > 0)
			ft_rra(a);
	}
	ft_pb(a, b);
}
