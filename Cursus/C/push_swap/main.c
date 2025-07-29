/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:40:42 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/29 18:16:06 by adriescr         ###   ########.fr       */
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
		return (
			ft_putstr_error("Error\n Error 1: No arguments provided.\n"), -1);
	if (!ft_check_args(argc, argv))
		return (ft_putstr_error("Error\n Error 2: Invalid arguments.\n"), -1);
	stack_a = create_stack_from_args(argc, argv);
	if (!stack_a)
		return (
			ft_putstr_error("Error\n Error 3: Allocation failed.\n"), -1);
	if (ft_push_swap(&stack_a, &stack_b))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (
			ft_putstr_error("Error\n Error 10: Operation failed.\n"), -1);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
