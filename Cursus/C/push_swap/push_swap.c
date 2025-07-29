/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:31:47 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/29 18:13:12 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_assign_indexes(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*tmp;
	int		index;

	curr = stack;
	while (curr)
	{
		index = 0;
		tmp = stack;
		while (tmp)
		{
			if (curr->value > tmp->value)
				index++;
			tmp = tmp->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}

int	get_chunk_size(int stack_size)
{
	if (stack_size <= 100)
		return (stack_size / 5);
	else
		return (stack_size / 11);
}

int	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk_size;
	int	size;

	if (!stack_a || !*stack_a)
		return (ft_putstr_error("Error\nError 9: Stack A is empty.\n"));
	ft_assign_indexes(*stack_a);
	size = ft_stack_size(*stack_a);
	if (size == 2)
		return (ft_sort_two(stack_a));
	if (size == 3)
		return (ft_sort_three(stack_a));
	if (size == 4)
		return (ft_sort_four(stack_a, stack_b));
	if (size == 5)
		return (ft_sort_five(stack_a, stack_b));
	chunk_size = get_chunk_size(size);
	push_chunks(stack_a, stack_b, chunk_size);
	push_back_sorted(stack_a, stack_b);
	return (0);
}
