/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:10:28 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/28 18:26:10 by adriescr         ###   ########.fr       */
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
	long	value;
	int		j;

	j = 0;
	stack = NULL;
	while (numbers[j])
	{
		if (!ft_is_number(numbers[j]))
			return (ft_putstr_error(
					"Error\n Error 5: Invalid number found.\n"), NULL);
		value = ft_atoi(numbers[j]);
		if (value < -2147483648 || value > 2147483647)
			return (ft_putstr_error(
					"Error\n Error 6: Number out of int range.\n"), NULL);
		stack = add_node_to_stack(stack, value);
		if (!stack)
			return (ft_putstr_error(
					"Error\n Error 7: Memory allocation failed.\n"), NULL);
		j++;
	}
	return (stack);
}

static t_stack	*create_stack_from_numbers(char **numbers)
{
	t_stack	*stack;

	stack = NULL;
	stack = parse_numbers(numbers);
	free_numbers(numbers);
	if (!stack)
		return (NULL);
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
			ft_putstr_error("Error\n Error 7: Invalid number found.\n");
			return (NULL);
		}
		stack = add_node_to_stack(stack, ft_atoi(argv[i]));
		if (!stack)
		{
			ft_putstr_error("Error\n Error 8: Memory allocation failed.\n");
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
			ft_putstr_error("Error\n Error 4: Splitting the string failed.\n");
			return (NULL);
		}
		return (create_stack_from_numbers(numbers));
	}
	else
		return (create_stack_from_argv(argc, argv));
}
