/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:37:27 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/08 19:04:53 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	skip_pipe(char *str, char **tokens, t_mem *mem)
{
	if (str[mem->i] == '|')
	{
		tokens[mem->k] = malloc(sizeof(char) * 3);
		tokens[mem->k][0] = '|';
		mem->i += 1;
		tokens[mem->k][1] = 0;
		if (str[mem->i] == '|')
		{
			tokens[mem->k][1] = '|';
			mem->i += 1;
			tokens[mem->k][2] = 0;
		}
		mem->k += 1;
	}
}

static void	skip_redir2(char *str, char **tokens, t_mem *mem)
{
	int	l;

	if (str[mem->i] == '<')
	{
		l = 0;
		tokens[mem->k] = malloc(sizeof(char) * 3);
		tokens[mem->k][l++] = str[mem->i];
		mem->i += 1;
		if (str[mem->i] == '<')
			tokens[mem->k][l++] = str[(mem->i)++];
		tokens[mem->k][l] = 0;
		mem->k += 1;
	}
	else if (str[mem->i] == '>')
	{
		l = 0;
		tokens[mem->k] = malloc(sizeof(char) * 3);
		tokens[mem->k][l++] = str[mem->i];
		mem->i += 1;
		if (str[mem->i] == '>')
			tokens[mem->k][l++] = str[(mem->i)++];
		tokens[mem->k][l] = 0;
		mem->k += 1;
	}
}

static void	skip_ampersand(char *str, char **tokens, t_mem *mem)
{
	if (str[mem->i] == '&' && str[mem->i + 1] == '&')
	{
		tokens[mem->k] = malloc(sizeof(char) * 3);
		tokens[mem->k][0] = '&';
		mem->i += 2;
		tokens[mem->k][1] = '&';
		tokens[mem->k][2] = 0;
		mem->k += 1;
	}
	else if (str[mem->i] == ' ')
		while (str[mem->i] == ' ')
			mem->i += 1;
}

static void	tokenizer_help(char *str, char **tokens, t_mem *mem)
{
	int	l;

	l = 0;
	if (mem->j > 0)
		tokens[mem->k] = malloc(sizeof(char) * (mem->j + 1));
	while (l < mem->j)
	{
		tokens[mem->k][l] = str[mem->i - mem->j + l];
		l++;
	}
	if (mem->j > 0)
	{
		tokens[mem->k][l] = 0;
		mem->k += 1;
	}
}

char	**tokenizer(char *str, t_mem *mem)
{
	char	**tokens;

	mem->i = 0;
	mem->k = 0;
	mem->found = 0;
	mem->squote = 0;
	mem->dquote = 0;
	tokens = malloc(sizeof(char *) * (count_token(str, mem) + 1));
	while (str[mem->i])
	{
		mem->j = 0;
		while (str[mem->i] == ' ' || str[mem->i] == '\t')
			mem->i++;
		quote_skip2(str, mem);
		tokenizer_help(str, tokens, mem);
		if (str[mem->i] == '|')
			skip_pipe(str, tokens, mem);
		else if (str[mem->i] == '>' || str[mem->i] == '<')
			skip_redir2(str, tokens, mem);
		else if (str[mem->i] == '&' || str[mem->i] == ' ')
			skip_ampersand(str, tokens, mem);
	}
	tokens[mem->k] = 0;
	return (tokens);
}
