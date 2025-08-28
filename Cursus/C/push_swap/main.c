/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:40:42 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/28 18:28:44 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (-1);
	if (!ft_check_args(argc, argv))
		return (ft_putstr_error("Error\n Error 2: Invalid arguments.\n"), -1);
	stack_a = create_stack_from_args(argc, argv);
	if (ft_check(stack_a) == 1)
		return (free_stack(stack_a), -1);
	if (ft_push_swap(&stack_a, &stack_b) != 0)
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
