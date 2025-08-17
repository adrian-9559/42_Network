/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:26:32 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 15:12:23 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

/*
 * ENGLISH: Initializes the pipex context structure with file descriptors 
 * and command-line arguments.
 *
 * SPANISH: Inicializa la estructura de contexto de pipex con 
 * descriptores de archivo y argumentos de línea de comandos.	
 *
 * @param {t_pipex_ctx} ctx   The pipex context structure to initialize. / 
 * 								La estructura de contexto de pipex a inicializar.
 * @param {char **} argv      The command-line arguments passed to the program. /
 * 								Los argumentos de línea de comandos pasados al 
 * 								programa.
 * @param {char **} envp      The environment variables passed to the program. /
 * 								Las variables de entorno pasadas al programa.
 *
 * @returns {int}
 * 
 * - Returns 0 on success, or 1 on error.
 * 
 * - Devuelve 0 en caso de éxito, o 1 en caso de error.
 *
 * @throws {Error}
 * 
 * - Throws an error if the input file cannot be opened or if the pipe cannot be 
 * 	created.
 * 
 * - Lanza un error si no se puede abrir el archivo de entrada o si no se puede 
 * 	crear el pipe.
 */
int	ft_pipex_init(t_pipex_ctx *ctx, char **argv, char **envp)
{
	int	ret;

	ret = 0;
	ctx->argv = argv;
	ctx->envp = envp;
	ctx->infile_error = 0;
	ctx->infile = ft_open_infile(argv[1], &ctx->infile_error);
	ctx->outfile = ft_open_outfile(argv[4], ctx->infile, ctx->infile_error);
	if (ctx->outfile < 0)
		ret = 1;
	if (ret == 0 && pipe(ctx->fd) == -1)
	{
		perror("pipex: pipe");
		if (!ctx->infile_error)
			close(ctx->infile);
		close(ctx->outfile);
		ret = 1;
	}
	return (ret);
}
