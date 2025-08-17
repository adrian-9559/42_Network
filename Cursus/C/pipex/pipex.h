/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:27:05 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 15:27:44 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <errno.h>
# include "lib/lib.h"

/*
 * ENGLISH: Represents the context structure for the pipex program.
 *
 * - Contains file descriptors for input and output files, pipe ends, 
 * command-line arguments, and environment variables.
 * - Used to manage and transfer execution context data within the pipex system.
 * - Ensure all required fields are properly initialized before use.
 *
 * SPANISH: Representa la estructura de contexto para el programa pipex.
 *
 * - Contiene descriptores de archivos para los archivos de entrada y salida, 
 * extremos de pipe, argumentos de línea de comandos y variables de entorno.
 * - Se utiliza para gestionar y transferir datos de contexto de ejecución 
 * dentro del sistema pipex.
 * - Asegúrese de que todos los campos requeridos estén correctamente 
 * inicializados antes de usar.
 *
 * struct s_pipex_ctx
 *
 *      - Structure holding pipex execution context data.
 *      - Estructura que contiene los datos de contexto de ejecución de pipex.
 *
 * @member {int} infile
 *      - File descriptor for the input file.
 *      - Descriptor de archivo para el archivo de entrada.
 *
 * @member {int} infile_error
 *      - Error status for input file opening.
 *      - Estado de error al abrir el archivo de entrada.
 *
 * @member {int[2]} fd
 *      - File descriptors for the pipe ends.
 *      - Descriptores de archivo para los extremos del pipe.
 *
 * @member {int} outfile
 *      - File descriptor for the output file.
 *      - Descriptor de archivo para el archivo de salida.
 *
 * @member {char **} argv
 *      - Command-line arguments.
 *      - Argumentos de línea de comandos.
 *
 * @member {char **} envp
 *      - Environment variables.
 *      - Variables de entorno.
 */
typedef struct s_pipex_ctx
{
	int		infile;
	int		infile_error;
	int		fd[2];
	int		outfile;
	char	**argv;
	char	**envp;
}	t_pipex_ctx;

// Main function
int		ft_pipex(int argc, char **argv, char **envp);

// Utility functions
int		ft_pipex_init(t_pipex_ctx *ctx, char **argv, char **envp);
void	ft_pipex_cleanup(t_pipex_ctx *ctx);
int		ft_open_infile(const char *filename, int *infile_error);
int		ft_open_outfile(const char *filename, int infile, int infile_error);
void	child1_process(t_pipex_ctx *ctx);
void	child2_process(t_pipex_ctx *ctx);

#endif