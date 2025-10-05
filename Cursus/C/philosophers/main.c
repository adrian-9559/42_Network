/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:03:39 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/05 17:03:57 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv, char **envp)
{
	const char		*name_function = "(main.c)";
	t_data			data;
	int				ret;

	if (argc != 5 && argc != 6)
	{
		ft_error(name_function, (char *[2]){ERR_NUM_ARGS, NULL});
		return (1);
	}
	data = ft_construct_data(argc, argv, envp);
	if (ft_create_thread(&data) != 0)
		return (1);
	ret = ft_philosophers(&data);
	ft_cleanup_data(&data);
	return (ret);
}
