/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:21:24 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/11 16:18:42 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_token_type(char *s, char *prev, int *new_cmd)
{
	if (is_meta_char(s))
	{
		if (is_logical(s) || !ft_strcmp(s, "|"))
			*new_cmd = 0;
		return (is_meta_char(s));
	}
	else if (!ft_strcmp(prev, "<"))
		return (INFILE);
	else if (!ft_strcmp(prev, "<<"))
		return (N_HEREDOC);
	else if (!ft_strcmp(prev, ">"))
		return (OUTFILE);
	else if (!ft_strcmp(prev, ">>"))
		return (OUTFILE);
	else if (*new_cmd == 0)
	{
		*new_cmd = 1;
		return (COMMAND);
	}
	else
		return (ARGUMENT);
}

static void	list_get_type(t_token **list)
{
	int		new_cmd;
	t_token	*temp;

	new_cmd = 0;
	if (is_meta_char((*list)->value))
		(*list)->type = is_meta_char((*list)->value);
	else
	{
		(*list)->type = COMMAND;
		new_cmd = 1;
	}
	temp = (*list)->next;
	while (temp)
	{
		temp->type = get_token_type(temp->value, temp->prev->value, &new_cmd);
		temp = temp->next;
	}
}

t_token	*tokens_to_list(char **tokens)
{
	int		i;
	t_token	*node;
	t_token	*list;

	if (!tokens || !*(tokens))
		return (NULL);
	i = 1;
	list = gen_new_token(tokens[0]);
	if (!list)
		return (NULL);
	while (tokens[i])
	{
		node = gen_new_token(tokens[i]);
		if (!node)
			return (free_tokens(list), NULL);
		token_add_back(&list, node);
		i++;
	}
	list_get_type(&list);
	return (list);
}
