/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:28:47 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/29 18:13:29 by adriescr         ###   ########.fr       */
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

void	push_chunks(t_stack **a, t_stack **b, int chunk_size)
{
	int	i;
	int	total;

	i = 0;
	total = ft_stack_size(*a);
	while (i < total)
	{
		if ((*a)->index < i)
		{
			ft_pb(a, b);
			ft_rb(b);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			ft_pb(a, b);
			i++;
		}
		else
			ft_ra(a);
	}
}

void	push_back_sorted(t_stack **a, t_stack **b)
{
	t_stack	*max_node;
	int		max_index;

	while (*b)
	{
		max_index = get_max_index(*b);
		if (get_position(*b, max_index) <= ft_stack_size(*b) / 2)
			while ((*b)->index != max_index)
				ft_rb(b);
		else
			while ((*b)->index != max_index)
				ft_rrb(b);
		ft_pa(a, b);
	}
}

int	get_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}
