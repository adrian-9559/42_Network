/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_cmd_in_paths.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:17:43 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:47:37 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

/*
 * ENGLISH: Searches for a command in the provided paths.
 *
 * SPANISH: Busca un comando en las rutas proporcionadas.
 *
 * @param {char **} paths
 *      - Array of paths to search in.
 *      - Array de rutas donde buscar.
 * @param {char *} cmd
 *      - Command to search for.
 *      - Comando a buscar.
 *
 * @returns {char *}
 *      - Returns the full path of the command if found, NULL otherwise.
 *      - Retorna la ruta completa del comando si se encuentra, NULL en
 *      caso contrario.
 */
char	*ft_search_cmd_in_paths(char **paths, char *cmd)
{
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		full_path = malloc(ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
		if (!full_path)
			break ;
		ft_strcpy(full_path, paths[i]);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, cmd);
		if (access(full_path, X_OK) == 0)
		{
			ft_free_split(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	ft_free_split(paths);
	return (NULL);
}
