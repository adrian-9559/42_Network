/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:59:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/28 18:21:36 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_check_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	if (!stack)
		return (1);
	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	ft_check(t_stack *stack)
{
	if (ft_check_duplicates(stack) == 1)
		return (ft_putstr_error("Error\n Error 4: Duplicates found.\n"), 1);
	return (0);
}
