/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:14:27 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 17:44:24 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

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
