/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_and_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:47:56 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/11 00:42:23 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	begin_of_all(t_mem *mem, char **argv, char **envp)
{
	if (!getenv("PATH"))
	{
		printf("Error: Shut down due to lack of environment variables\n");
		exit(0);
	}
	mem->saved_stdin = dup(STDIN_FILENO);
	mem->saved_stdout = dup(STDOUT_FILENO);
	mem->argv = argv;
	mem->envp = envp;
	mem->values = sort_env(envp);
	mem->my_env = env_dup(envp);
}

int	init_mem(t_mem *mem)
{
	if (!check_quotes(mem->input))
	{
		mem->exit_stat = 2;
		return (free(mem->input), 0);
	}
	mem->cmd_exist = 0;
	mem->wait = 0;
	mem->word = 0;
	mem->status = 0;
	mem->exit = 0;
	mem->args = tokenizer(mem->input, mem);
	if (!mem->args || !mem->args[0])
		return (free(mem->input), 0);
	if (!check_metas(mem->args))
	{
		mem->exit_stat = 2;
		return (free(mem->input), free_tab(mem->args), 0);
	}
	mem->paths = get_paths(mem->my_env);
	if (!mem->paths)
		return (free(mem->input), free_tab(mem->args), 0);
	mem->tokens = tokens_to_list(mem->args);
	if (!mem->tokens)
		return (free(mem->input), free_tab(mem->args), free_tab(mem->paths), 0);
	return (1);
}

void	free_mem(t_mem *mem)
{
	g_pid = 0;
	free(mem->input);
	if (mem->cmd_exist)
		free(mem->last_cmd);
	free_tab(mem->args);
	free_tab(mem->paths);
	free_tokens(mem->tokens);
}

void	end_of_all(t_mem *mem)
{
	close(mem->saved_stdin);
	close(mem->saved_stdout);
	free_env(mem->values);
	free_env(mem->my_env);
	rl_clear_history();
	printf("exit\n");
}
