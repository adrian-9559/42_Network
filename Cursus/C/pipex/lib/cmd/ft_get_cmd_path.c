/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:46:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 17:57:50 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

/*
 * ENGLISH: Retrieves the full path of a command from the PATH environment 
 *			variable.
 *
 * SPANISH: Recupera la ruta completa de un comando desde la variable de 
 * 			entorno PATH.
 *
 * @param {char *} cmd
 *		- The command to find the path for. \ 
 *		El comando para el cual se busca la ruta.
 * @param {char **} envp
 *		- The environment variables array containing the PATH variable. \ 
 *		El arreglo de variables de entorno que contiene la variable PATH.
 *
 * @returns {char *}
 * 
 *      - Returns the full path of the command if found, NULL otherwise.
 * 
 *      - Retorna la ruta completa del comando si se encuentra, NULL en
 *      caso contrario.
 */
char	*ft_get_cmd_path(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;

	if (!cmd || !envp)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	path_env = ft_extract_path(envp);
	if (!path_env)
		path_env = ft_strdup("/usr/bin:/bin");
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	return (ft_search_cmd_in_paths(paths, cmd));
}
