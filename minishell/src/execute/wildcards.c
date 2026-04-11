/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:28:40 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/10 18:58:30 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_match(char *name, char *str)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	j = 0;
	if (str[0] != '*' && str[0] != name[0])
		return (0);
	while (str[i])
	{
		while (str[i] == '*')
			i++;
		if (!str[i])
			return (1);
		sub = ft_substr(str + i, 0, ft_strchr(str + i, '*'));
		if (!sub)
			return (0);
		j += index_n(name + j, sub, 1);
		free(sub);
		if (!name[j])
			return (0);
		i++;
	}
	return (1);
}

static t_token	*create_match_list(char *str)
{
	DIR				*d;
	struct dirent	*name;
	t_token			*list;

	d = opendir(".");
	if (!d)
	{
		perror("opendir");
		return (0);
	}
	name = readdir(d);
	list = NULL;
	while (name)
	{
		if (name->d_name[0] != '.' && is_match(name->d_name, str))
			token_add_back(&list, gen_new_token(ft_strdup(name->d_name)));
		name = readdir(d);
	}
	closedir(d);
	return (list);
}

void	expand_from_wc(t_token **token)
{
	t_token	*list;
	t_token	*next;
	t_token	*prev;

	list = create_match_list((*token)->value);
	if (!list)
		return ;
	next = (*token)->next;
	prev = (*token)->prev;
	prev->next = list;
	list->prev = prev;
	while (list->next)
		list = list->next;
	list->next = next;
	if (next)
		next->prev = list;
	free(*token);
	*token = prev;
}
