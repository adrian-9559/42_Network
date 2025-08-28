/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:47:18 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/28 17:58:58 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	ft_check_token_is_number(char *token)
{
	if (!ft_is_number(token))
		return (0);
	return (1);
}

static int	ft_check_arg_tokens(char *arg)
{
	char	*token;
	char	*start;
	char	tmp;

	token = arg;
	while (*token)
	{
		while (*token == ' ')
			token++;
		if (*token == '\0')
			return (1);
		start = token;
		while (*token && *token != ' ')
			token++;
		tmp = *token;
		*token = '\0';
		if (!ft_check_token_is_number(start))
			return (0);
		*token = tmp;
		if (*token)
			token++;
	}
	return (1);
}

int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_check_arg_tokens(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
