/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:59:28 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/08 22:05:13 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	free_numbers(char **numbers)
{
	int	j;

	j = 0;
	if (!numbers)
		return ;
	while (numbers[j])
		free(numbers[j++]);
	free(numbers);
}

t_stack	*reverse_stack(t_stack *stack)
{
	t_stack	*prev;
	t_stack	*current;
	t_stack	*next;

	prev = NULL;
	current = stack;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return (prev);
}
