/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:45:58 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 13:23:43 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

static void	*free_all(char **arr, size_t j)
{
	while (j > 0)
		free(arr[--j]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	vars[4];
	char	**res;

	vars[0] = 0;
	vars[1] = 0;
	vars[2] = ft_count_words(s, c);
	res = malloc((vars[2] + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (vars[1] < vars[2])
	{
		while (s[vars[0]] == c)
			vars[0]++;
		vars[3] = vars[0];
		while (s[vars[0]] && s[vars[0]] != c)
			vars[0]++;
		res[vars[1]] = malloc(vars[0] - vars[3] + 1);
		if (!res[vars[1]])
			return (free_all(res, vars[1]));
		ft_memcpy(res[vars[1]], s + vars[3], vars[0] - vars[3]);
		res[vars[1]][vars[0] - vars[3]] = '\0';
		vars[1]++;
	}
	res[vars[1]] = NULL;
	return (res);
}
