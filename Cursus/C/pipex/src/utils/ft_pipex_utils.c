/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:14:27 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 17:51:03 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

/*
 * ENGLISH: Opens an input file with the specified name.
 *
 * SPANISH: Abre un archivo de entrada con el nombre especificado.
 *
 * @param filename   
 * 					The name of the file to open. / 
 * 					El nombre del archivo a abrir.
 * @param outfile     
 * 					File descriptor for the output file. / 
 * 					Descriptor de archivo para el archivo de salida.
 * @param outfile_error
 * 					Error status for output file opening. / 
 * 					Estado de error al abrir el archivo de salida.
 *
 * @return {int}
 * 
 * - Returns the file descriptor if successful, or -1 on error.
 * 
 * - Devuelve el descriptor de archivo si tiene éxito, o -1 en caso de error.
 */
void	child1_process(t_pipex_ctx *ctx)
{
	int	devnull;

	if (ctx->infile_error)
	{
		devnull = open("/dev/null", O_RDONLY);
		dup2(devnull, 0);
		close(devnull);
	}
	else
		dup2(ctx->infile, 0);
	dup2(ctx->fd[1], 1);
	close(ctx->fd[0]);
	close(ctx->fd[1]);
	if (!ctx->infile_error)
		close(ctx->infile);
	close(ctx->outfile);
	ft_exec_cmd(ctx->argv[2], ctx->envp);
}

/*
 * ENGLISH: Opens an output file with the specified name.
 *
 * SPANISH: Abre un archivo de salida con el nombre especificado.
 *
 * @param filename   
 * 					The name of the file to open. / 
 * 					El nombre del archivo a abrir.
 * @param infile     
 * 					File descriptor for the input file. / 
 * 					Descriptor de archivo para el archivo de entrada.
 * @param infile_error
 * 					Error status for input file opening. / 
 * 					Estado de error al abrir el archivo de entrada.
 *
 * @return {int}
 * 
 * - Returns the file descriptor if successful, or -1 on error.
 * 
 * - Devuelve el descriptor de archivo si tiene éxito, o -1 en caso de error.
 */
void	child2_process(t_pipex_ctx *ctx)
{
	dup2(ctx->fd[0], 0);
	dup2(ctx->outfile, 1);
	close(ctx->fd[0]);
	close(ctx->fd[1]);
	if (!ctx->infile_error)
		close(ctx->infile);
	close(ctx->outfile);
	ft_exec_cmd(ctx->argv[3], ctx->envp);
}
