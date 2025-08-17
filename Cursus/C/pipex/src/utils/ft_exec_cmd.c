/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 12:52:46 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:05:31 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

/*
 * ENGLISH: Executes a command in the system.
 *
 * SPANISH: Ejecuta un comando en el sistema.
 *
 * @param cmd   The name of the command to execute. / 
 * 				El nombre del comando a ejecutar.
 * @param envp  The environment variables to use when executing the command. / 
 *				Las variables de entorno a utilizar al ejecutar el comando.
 *
 * @returns {Promise<void>}
 *
 * - Resolves if the command is executed successfully.
 *
 * - Se resuelve si el comando se ejecuta con éxito.
 */
int	ft_exec_cmd(char *cmd, char **envp)
{
	char	**argv_exec;
	char	*cmd_path;

	argv_exec = ft_split_shell(cmd);
	if (!argv_exec || !argv_exec[0])
	{
		ft_print_error_str("pipex: ");
		ft_print_error_str(cmd);
		ft_print_error_str(": command not found\n");
		ft_free_split(argv_exec);
		exit(127);
	}
	cmd_path = ft_get_cmd_path(argv_exec[0], envp);
	if (cmd_path)
		execve(cmd_path, argv_exec, envp);
	ft_print_error_str("pipex: ");
	ft_print_error_str(cmd);
	ft_print_error_str(": command not found\n");
	ft_free_split(argv_exec);
	exit(127);
}
