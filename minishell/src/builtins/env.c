/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:26:27 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/08 02:00:45 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*env_new_node(char *s)
{
	t_env	*node;
	size_t	i;

	node = malloc(sizeof (t_env));
	if (!node || !s)
		return (NULL);
	i = ft_strchr(s, '=');
	node->key = ft_substr(s, 0, i);
	if (!node->key)
		return (NULL);
	node->value = ft_substr(s, i + 1, ft_strlen(s));
	if (!node->value)
		return (free(node->key), NULL);
	node->is_unset = 0;
	node->next = NULL;
	return (node);
}

t_env	*env_dup(char **envp)
{
	t_env	*list;
	t_env	*temp;
	size_t	x;

	list = env_new_node(envp[0]);
	temp = list;
	x = 1;
	while (envp[x])
	{
		temp->next = env_new_node(envp[x]);
		temp = temp->next;
		x++;
	}
	return (list);
}

t_env	*sort_env(char **envp)
{
	t_env	*list;
	t_env	*temp;
	int		i;

	list = NULL;
	temp = NULL;
	i = 0;
	while (envp[i])
	{
		temp = add_env(envp[i], &list);
		if (!list)
			list = temp;
		i++;
	}
	return (list);
}

int	ft_env(t_env *env, t_mem *mem)
{
	t_env	*temp;

	temp = env;
	if (!env || !env->key)
		return (1);
	while (temp)
	{
		if (!temp->is_unset)
			printf("%s=\"%s\"\n", temp->key, temp->value);
		temp = temp->next;
	}
	mem->exit_stat = 0;
	return (0);
}

void	free_env(t_env *env)
{
	t_env	*temp;

	while (env)
	{
		temp = env;
		env = env->next;
		if (temp->key)
			free(temp->key);
		if (temp->value)
			free(temp->value);
		free(temp);
	}
}
