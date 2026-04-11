/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:45:48 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/11 17:14:58 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/signal.h>
# include <errno.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

extern pid_t	g_pid;

typedef enum e_token_type
{
	ARGUMENT,
	INFILE,
	OUTFILE,
	HEREDOC,
	N_HEREDOC,
	APPEND,
	REDIRECT_IN,
	REDIRECT_OUT,
	PIPE,
	AND,
	OR,
	COMMAND
}	t_token_type;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				is_unset;
	struct s_env	*next;
}	t_env;

typedef struct s_expand
{
	char	*s;
	char	*sub;
	char	*key;
	size_t	i;
	size_t	n;
	size_t	len;
}	t_expand;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_cmd
{
	char	*command;
	char	**args;
	int		fd[2];
	int		infile;
	int		outfile;
	int		heredoc;
	int		count;
}	t_cmd;

typedef struct s_mem
{
	int		i;
	int		j;
	int		k;
	int		wait;
	int		exit;
	int		status;
	char	*input;
	int		found;
	int		squote;
	int		dquote;
	int		word;
	int		count;
	int		saved_stdin;
	int		saved_stdout;
	char	**args;
	char	**argv;
	char	**envp;
	int		exit_stat;
	t_env	*my_env;
	t_env	*values;
	char	**paths;
	t_token	*tokens;
	t_cmd	*cmds;
	pid_t	*pids;
	int		index;
	int		pipe_num;
	int		cmd_exist;
	char	*last_cmd;
}	t_mem;

// ---parsing--- //

// check_quotes
int		index_n(char *s, char *c, int n);
size_t	next_quote(char *s);
int		check_quotes(char *s);

// check_metas
int		is_meta_char(char *s);
int		is_redirect(char *s);
int		is_logical(char *s);
int		is_end_command(t_token *arg);
int		check_metas(char **tokens);
void	increase_i_j(int *i, int *j);

// tokenizer
void	quote_skip2_helper(char *str, t_mem *mem);
void	quote_skip2(char *str, t_mem *mem);
void	quote_skip(char *str, int *i, t_mem *mem);
void	skip_redir(char *str, int *count, int *i);
int		count_token(char *str, t_mem *mem);
char	**tokenizer(char *str, t_mem *mem);
t_token	*tokens_to_list(char **tokens);

// token_utils
t_token	*gen_new_token(char	*s);
void	token_add_back(t_token **list, t_token *node);
void	free_tokens(t_token *tokens);

// ---builtins--- //

int		is_builtins(char *s);
int		do_builtins(t_token *arg, t_mem *mem);
int		ft_echo(t_token *arg, t_mem *mem);
int		ft_cd(t_token *arg, t_mem *mem);
int		ft_pwd(t_env *env, t_mem *mem);
int		ft_env(t_env *env, t_mem *mem);
int		ft_export(t_env *env, t_token *arg, t_mem *mem);
int		ft_unset(t_env *my_env, t_env *values, t_token *arg, t_mem *mem);
int		ft_exit(t_token *arg, t_mem *mem);
t_env	*env_new_node(char *s);
t_env	*env_dup(char **envp);
t_env	*sort_env(char **envp);
t_env	*add_env(char *s, t_env **env);
char	*my_getenv(char *key, t_env *env);
void	free_env(t_env *env);

// ---execute--- //

int		expand(t_token **list, t_env *env, t_mem *mem);
char	*expansion(char *str, t_env *env, t_mem *mem);
char	*remove_quotes(char *str, t_env *env, t_mem *mem);
void	expand_from_wc(t_token **token);
int		command_check(t_token *list, t_mem *mem);
int		get_fds(t_token *list, t_cmd *cmd, t_mem *mem);
int		execute(t_mem *mem);

int		exec_command(t_cmd *cmd, t_token *list, t_mem *mem);
int		ft_command(t_token *list, t_mem *mem);
int		last_child(t_token *list, t_mem *mem);
void	get_exit_stat(char *s, t_mem *mem);

// baby_sitter
void	redirect(t_cmd *cmd);
void	do_command(t_token *list, t_cmd *cmd, t_mem *mem, int status);

// utils
char	*my_strjoin(char *s1, char *s2);
int		open_here_doc(void);
int		open_file(char *file, int n, t_mem *mem);
char	**get_paths(t_env *env);
char	*get_command(char **paths, char *cmd);

// more_utils
int		count_args(t_token *list);
int		get_args(char ***args, t_token *list);
void	free_tab(char **tab);
int		get_here_doc_input(char *eof, t_mem *mem);
void	result_handler(int argc);

// ---signals--- //
void	sig_init_signals(void);
void	sigint_handler(int signo);
void	child_sig_init(void);

// ---main--- //

void	begin_of_all(t_mem *mem, char **argv, char **envp);
int		init_mem(t_mem *mem);
void	free_mem(t_mem *mem);
void	end_of_all(t_mem *mem);

#endif
