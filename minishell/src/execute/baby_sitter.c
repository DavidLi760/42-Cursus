/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baby_sitter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:46:20 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/11 18:30:06 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	redirect(t_cmd *cmd)
{
	if (cmd->infile > STDIN_FILENO)
	{
		dup2(cmd->infile, STDIN_FILENO);
		close(cmd->infile);
	}
	if (cmd->outfile > STDOUT_FILENO)
	{
		dup2(cmd->outfile, STDOUT_FILENO);
		close(cmd->outfile);
	}
}

static void	execute_builtins(t_token *list, t_cmd *cmd, t_mem *mem)
{
	do_builtins(list, mem);
	if (cmd->infile > STDIN_FILENO)
		close(cmd->infile);
	if (cmd->outfile > STDOUT_FILENO)
		close(cmd->outfile);
	free(cmd->command);
	free_tab(cmd->args);
	close(mem->saved_stdin);
	close(mem->saved_stdout);
	exit(0);
}

static void	clear_execve(t_cmd *cmd, t_mem *mem)
{
	perror("execve");
	if (cmd->infile > STDIN_FILENO)
		close(cmd->infile);
	if (cmd->outfile > STDOUT_FILENO)
		close(cmd->outfile);
	free(cmd->command);
	free_tab(cmd->args);
	close(mem->saved_stdin);
	close(mem->saved_stdout);
	exit(0);
}

static void	deal_pipe(t_cmd *cmd)
{
	close(cmd->fd[0]);
	if (cmd->outfile <= STDOUT_FILENO)
	{
		dup2(cmd->fd[1], STDOUT_FILENO);
		close(cmd->fd[1]);
	}
	else
		close(cmd->fd[1]);
}

void	do_command(t_token *list, t_cmd *cmd, t_mem *mem, int status)
{
	mem->pids[mem->index] = fork();
	if (mem->pids[mem->index] < 0)
		perror("Fork error");
	if (mem->pids[mem->index] == 0)
	{
		redirect(cmd);
		child_sig_init();
		if (status == 1)
			deal_pipe(cmd);
		if (is_builtins(cmd->command))
			execute_builtins(list, cmd, mem);
		else
		{
			if (execve(cmd->command, cmd->args, mem->envp))
				clear_execve(cmd, mem);
		}
	}
}
