/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:03:05 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/28 17:41:13 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// Functions lib
int		ft_putstr_error(const char *str);
int		ft_putstr(const char *str);
int		ft_putchar(char c);
int		ft_putchar_error(char c);
int		ft_is_digit(unsigned char c);
int		ft_is_number(const char *str);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);

// Stack operations
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

// Main functions
int		ft_check_args(int argc, char **argv);
int		ft_check_duplicates(t_stack *stack);
t_stack	*create_stack_from_args(int argc, char **argv);
int		ft_stack_size(t_stack *stack);
void	free_stack(t_stack *stack);
void	free_numbers(char **numbers);
t_stack	*reverse_stack(t_stack *stack);
int		find_min(t_stack *stack);
int		find_min_index(t_stack *stack);
int		ft_push_swap(t_stack **stack_a, t_stack **stack_b);
void	ft_assign_indexes(t_stack *stack);
int		get_chunk_size(int stack_size);
void	push_chunks(t_stack **a, t_stack **b, int chunk_size);
void	push_back_sorted(t_stack **a, t_stack **b);
int		get_max_index(t_stack *stack);
int		get_position(t_stack *stack, int index);

// Sorting functions
int		ft_sort_two(t_stack **stack_a);
int		ft_sort_three(t_stack **stack_a);
int		ft_sort_four(t_stack **stack_a, t_stack **stack_b);
int		ft_sort_five(t_stack **stack_a, t_stack **stack_b);
int		ft_sort_big(t_stack **stack_a, t_stack **stack_b);

#endif