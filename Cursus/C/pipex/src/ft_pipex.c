/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:12:12 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 17:41:30 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
 * ENGLISH: Retrieve a list of all users from the system.
 *
 * - Fetches all user records stored in the database.
 *
 * - Returns an array containing user objects.
 *
 * - If no users are found, returns an empty array.
 *
 * - If an error occurs during retrieval, an exception is thrown.
 *
 * SPANISH: Recuperar una lista de todos los usuarios del sistema.
 *
 * - Obtiene todos los registros de usuarios almacenados en la base de datos.
 *
 * - Retorna un arreglo que contiene objetos de usuario.
 *
 * - Si no se encuentran usuarios, retorna un arreglo vacío.
 *
 * - Si ocurre un error durante la recuperación, la función lanza una excepción.
 *
 * @returns {Promise<User[]>}
 *
 *      - Returns an array of user objects.
 *
 *      - Retorna un arreglo de objetos de usuario.
 *
 * @throws {Error}
 *
 *      - If an error occurs while retrieving users.
 *
 *      - Si ocurre un error al recuperar los usuarios.
 */
int	ft_pipex(int argc, char **argv, char **envp)
{
	t_pipex_ctx	ctx;
	pid_t		pid1;
	pid_t		pid2;
	int			status1;
	int			status2;

	if (argc != 5)
	{
		ft_print_error_str("Usage: ./pipex infile cmd1 cmd2 outfile\n");
		return (1);
	}
	if (ft_pipex_init(&ctx, argv, envp))
		return (1);
	pid1 = fork();
	if (pid1 == 0)
		child1_process(&ctx);
	pid2 = fork();
	if (pid2 == 0)
		child2_process(&ctx);
	ft_pipex_cleanup(&ctx);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	return ((status2 >> 8) & 0xFF);
}
