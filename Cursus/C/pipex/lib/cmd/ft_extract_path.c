/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:43:41 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:47:13 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

/*
 * ENGLISH: Extracts the PATH variable from the environment variables.
 *
 * SPANISH: Extrae la variable PATH del entorno.
 *
 * @param {string} envp
 * 
 * 	 - The environment variables array containing the PATH variable.
 * 
 * 	 - El arreglo de variables de entorno que contiene la variable PATH.
 *
 * @returns {string}
 * 
 * 	  - Returns the extracted PATH string if found.
 * 
 * 	  - Retorna la cadena PATH extraída si se encuentra.
 * 
 * @throws {Error}
 *
 *    - Returns NULL if the PATH variable is not found in the environment 
 * 		variables.
 * 
 *	  - Devuelve NULL si no se encuentra la variable PATH en las variables
 *		de entorno.
 */
char	*ft_extract_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}
