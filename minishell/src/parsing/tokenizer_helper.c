/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:37:27 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/07 16:55:19 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	quote_skip2_helper(char *str, t_mem *mem)
{
	if (str[mem->i] == '\'')
		mem->squote = 1;
	if (str[mem->i] == '"')
		mem->dquote = 1;
}

void	quote_skip2(char *str, t_mem *mem)
{
	while (str[mem->i] != ' ' && str[mem->i] != '>' && str[mem->i] != '<'
		&& (str[mem->i] != '&' || str[mem->i + 1] != '&')
		&& str[mem->i] != '|' && str[mem->i])
	{
		quote_skip2_helper(str, mem);
		if (mem->squote || mem->dquote)
			increase_i_j(&(mem->i), &(mem->j));
		while ((mem->squote == 1 || mem->dquote == 1) && str[mem->i])
		{
			if (str[mem->i] == '\'' && mem->squote == 1)
				mem->squote = 0;
			else if (str[mem->i] == '"' && mem->dquote == 1)
				mem->dquote = 0;
			increase_i_j(&(mem->i), &(mem->j));
		}
		if (str[mem->i] != ' ' && str[mem->i] != '>' && str[mem->i] != '<'
			&& str[mem->i] != '|' && str[mem->i]
			&& str[mem->i] != '\'' && str[mem->i] != '"')
		{
			mem->i += 1;
			mem->j += 1;
		}
	}
}

void	quote_skip(char *str, int *i, t_mem *mem)
{
	while (str[*i] != ' ' && str[*i] != '>' && str[*i] != '<' && str[*i] != '|'
		&& (str[*i] != '&' || str[*i + 1] != '&') && str[*i])
	{
		if (str[*i] == '\'')
			mem->squote = 1;
		else if (str[*i] == '"')
			mem->dquote = 1;
		if (mem->squote == 1 || mem->dquote == 1)
			*i += 1;
		while ((mem->squote == 1 || mem->dquote == 1) && str[*i])
		{
			if (str[*i] == '\'' && mem->squote == 1)
				mem->squote = 0;
			if (str[*i] == '"' && mem->dquote == 1)
				mem->dquote = 0;
			*i += 1;
		}
		if (str[*i] != ' ' && str[*i] != '>' && str[*i] != '<'
			&& str[*i] != '|' && str[*i] && str[*i] != '\'' && str[*i] != '"')
			*i += 1;
		mem->word = 1;
	}
}

void	skip_redir(char *str, int *count, int *i)
{
	if (str[*i] == '|')
	{
		*count += 1;
		*i += 1;
		if (str[*i] == '|')
			*i += 1;
	}
	else if (str[*i] == '<')
	{
		*count += 1;
		*i += 1;
		if (str[*i] == '<')
			*i += 1;
	}
	else if (str[*i] == '>')
	{
		*count += 1;
		*i += 1;
		if (str[*i] == '>')
			*i += 1;
	}
}

int	count_token(char *str, t_mem *mem)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		quote_skip(str, &i, mem);
		if (mem->word == 1)
		{
			mem->word = 0;
			count++;
		}
		if (str[i] == '|' || str[i] == '<' || str[i] == '>')
			skip_redir(str, &count, &i);
		else if (str[i] == '&' && str[i + 1] == '&')
		{
			count++;
			i += 2;
		}
	}
	return (count);
}
