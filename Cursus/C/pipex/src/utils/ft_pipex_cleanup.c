/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_cleanup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:15:03 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 13:25:15 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

/*
 * ENGLISH: Clean up resources used by the pipex context.
 *
 * - Closes both ends of the pipe stored in the context.
 * 
 * - Closes the input file descriptor if it was opened successfully.
 * 
 * - Closes the output file descriptor.
 *
 * - Ensures that all file descriptors associated with the
 *   context are properly closed to prevent resource leaks.
 *
 * SPANISH: Limpia los recursos utilizados por el contexto de pipex.
 *
 * - Cierra ambos extremos del pipe almacenados en el contexto.
 * 
 * - Cierra el descriptor de archivo de entrada si se abrió correctamente.
 * 
 * - Cierra el descriptor de archivo de salida.
 *
 * - Garantiza que todos los descriptores de archivo asociados
 *   al contexto se cierren correctamente para evitar fugas de recursos.
 *
 * @param {t_pipex_ctx *ctx}
 * 
 *      - Pointer to the pipex context containing file descriptors.
 * 
 *      - Puntero al contexto de pipex que contiene los descriptores de archivo.
 */
void	ft_pipex_cleanup(t_pipex_ctx *ctx)
{
	close(ctx->fd[0]);
	close(ctx->fd[1]);
	if (!ctx->infile_error)
		close(ctx->infile);
	close(ctx->outfile);
}
