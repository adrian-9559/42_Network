/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:40:42 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 01:52:58 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	print_stack(t_stack *stack, const char *name)
{
	t_stack	*current;

	printf("%s: ", name);
	current = stack;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		// No arguments provided
		return (ft_putstr_error("Error\n"), -1);
	if (!ft_check_args(argc, argv))
		// Invalid arguments
		return (ft_putstr_error("Error\n"), -1);
	stack_a = create_stack_from_args(argc, argv);
	if (!stack_a)
		// Memory allocation failed or invalid input
		return (ft_putstr_error("Error\n"), -1);
	push_swap(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
