/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:10:28 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 01:53:22 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static t_stack	*add_node_to_stack(t_stack *stack, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = stack;
	return (new_node);
}

static t_stack	*parse_numbers(char **numbers)
{
	t_stack	*stack;
	int		j;

	j = 0;
	stack = NULL;
	while (numbers[j])
	{
		if (!ft_is_number(numbers[j]))
		{
			// If the number is not valid, free the allocated memory and return NULL
			ft_putstr_error("Error\n");
			free_numbers(numbers);
			return (NULL);
		}
		stack = add_node_to_stack(stack, ft_atoi(numbers[j]));
		if (!stack)
		{
			// If memory allocation fails, free the numbers and return NULL
			ft_putstr_error("Error\n");
			free_numbers(numbers);
			return (NULL);
		}
		j++;
	}
	free_numbers(numbers);
	return (stack);
}

static t_stack	*create_stack_from_numbers(char **numbers)
{
	t_stack	*stack;

	stack = NULL;
	stack = parse_numbers(numbers);
	return (reverse_stack(stack));
}

static t_stack	*create_stack_from_argv(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		if (!ft_is_number(argv[i]))
		{
			// If the argument is not a valid number, return NULL
			ft_putstr_error("Error\n");
			return (NULL);
		}
		stack = add_node_to_stack(stack, ft_atoi(argv[i]));
		if (!stack)
		{
			// If memory allocation fails, return NULL
			ft_putstr_error("Error\n");
			return (NULL);
		}
		i++;
	}
	return (reverse_stack(stack));
}

t_stack	*create_stack_from_args(int argc, char **argv)
{
	char	**numbers;

	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers)
		{
			// If splitting the string fails, return NULL
			ft_putstr_error("Error\n");
			return (NULL);
		}
		return (create_stack_from_numbers(numbers));
	}
	else
		return (create_stack_from_argv(argc, argv));
}
