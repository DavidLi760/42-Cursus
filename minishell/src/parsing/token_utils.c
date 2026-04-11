/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:29:21 by xiaxu             #+#    #+#             */
/*   Updated: 2024/08/28 14:31:35 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*gen_new_token(char	*s)
{
	t_token	*node;

	node = malloc(sizeof (t_token));
	if (!node)
		return (NULL);
	node->value = ft_strdup(s);
	if (!node->value)
		return (free(node), NULL);
	node->type = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	token_add_back(t_token **list, t_token *node)
{
	t_token	*temp;

	temp = *list;
	if (!list || !*list)
		*list = node;
	while (temp)
	{
		if (!temp->next)
		{
			temp->next = node;
			node->prev = temp;
			break ;
		}
		temp = temp->next;
	}
}

void	free_tokens(t_token *tokens)
{
	t_token	*temp;

	while (tokens)
	{
		temp = tokens;
		tokens = tokens->next;
		if (temp->value)
			free(temp->value);
		free(temp);
	}
}
