/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:25:45 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 13:31:37 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * ENGLISH: Main function for the Pipex program.
 *
 * - Initializes the Pipex context and processes command line arguments.
 *
 * - Handles the execution of commands and manages input/output redirection.
 *
 * - Returns the exit status of the last executed command.
 *
 * SPANISH: Función principal para el programa Pipex.
 *
 * - Inicializa el contexto de Pipex y procesa los argumentos de la línea 
 * de comandos.
 *
 * - Maneja la ejecución de comandos y gestiona la redirección de entrada/salida.
 *
 * - Retorna el estado de salida del último comando ejecutado.
 */
int	main(int argc, char **argv, char **envp)
{
	return (ft_pipex(argc, argv, envp));
}
