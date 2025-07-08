/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:31:47 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/08 22:32:31 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && a < c)
		ft_sa(stack);
	else if (a > b && b > c)
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else if (a > b && b < c && a > c)
		ft_ra(stack);
	else if (a < b && b > c && a < c)
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if (a < b && b > c && a > c)
		ft_rra(stack);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	next_min;

	min = find_min(*a);
	push_value_to_b(a, b, min);
	next_min = find_min(*a);
	push_value_to_b(a, b, next_min);
	sort_three(a);
	if ((*b)->value < (*b)->next->value)
		ft_sb(b);
	ft_pa(a, b);
	ft_pa(a, b);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max_bits;
	int	counters[2];

	size = ft_stack_size(*stack_a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	counters[0] = 0;
	while (counters[0] < max_bits)
	{
		counters[1] = 0;
		while (counters[1] < size)
		{
			if ((((*stack_a)->value >> counters[0]) & 1) == 0)
				ft_pb(stack_a, stack_b);
			else
				ft_ra(stack_a);
			counters[1]++;
		}
		while (*stack_b)
			ft_pa(stack_a, stack_b);
		counters[0]++;
	}
}
