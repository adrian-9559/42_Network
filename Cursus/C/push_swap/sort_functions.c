/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:08:24 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/28 17:28:19 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_sort_two(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_sa(stack_a);
	return (0);
}

int	ft_sort_three(t_stack **stack_a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*stack_a)->value;
	n2 = (*stack_a)->next->value;
	n3 = (*stack_a)->next->next->value;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		ft_sa(stack_a);
	else if (n1 > n2 && n2 > n3)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ft_ra(stack_a);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		ft_rra(stack_a);
	return (0);
}

int	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a || ft_stack_size(*stack_a) < 4)
		return (0);
	while (ft_stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->value == find_min(*stack_a))
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	ft_sort_three(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
	return (0);
}

int	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;

	min_index = find_min_index(*stack_a);
	while (min_index-- > 0)
		ft_ra(stack_a);
	ft_pb(stack_a, stack_b);
	min_index = find_min_index(*stack_a);
	if (min_index <= 4 / 2)
		while (min_index-- > 0)
			ft_ra(stack_a);
	else
		while (min_index++ < 4)
			ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_pa(stack_b, stack_a);
	ft_pa(stack_b, stack_a);
}

int	ft_sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	vars[6];

	vars[0] = ft_stack_size(*stack_a);
	vars[1] = 0;
	while ((vars[0] - 1) >> vars[1])
		vars[1]++;
	vars[5] = 0;
	while (vars[5] < vars[1])
	{
		vars[2] = ft_stack_size(*stack_a);
		vars[3] = 0;
		while (vars[3] < vars[2])
		{
			if ((((*stack_a)->index >> vars[5]) & 1) == 0)
				ft_pb(stack_a, stack_b);
			else
				ft_ra(stack_a);
			vars[3]++;
		}
		while (*stack_b)
			ft_pa(stack_a, stack_b);
		vars[5]++;
	}
	return (0);
}
