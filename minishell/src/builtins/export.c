/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:59:05 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/08 19:59:40 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_valid_for_export(char *s)
{
	int	i;
	int	j;

	if (!ft_isalpha(s[0]) && s[0] != '_')
		return (0);
	i = 0;
	j = ft_strchr(s, '=');
	while (i < j)
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

t_env	*add_env(char *s, t_env **env)
{
	t_env	*node;
	t_env	*temp;

	node = env_new_node(s);
	if (!node)
		return (NULL);
	if (!*env || !(*env)->key)
		return (*env = node, node);
	temp = *env;
	while (temp)
	{
		if (!ft_strcmp(node->key, temp->key))
		{
			free(temp->value);
			temp->value = ft_strdup(node->value);
			return (free(node), NULL);
		}
		if (!temp->next || ft_strcmp(node->key, temp->next->key) < 0)
			break ;
		temp = temp->next;
	}
	node->next = temp->next;
	temp->next = node;
	return (node);
}

static int	ft_print_export(t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		if (temp->is_unset == 0)
		{
			if (ft_strcmp(temp->value, "") > 0)
				printf("export %s=\"%s\"\n", temp->key, temp->value);
			else
				printf("export %s\n", temp->key);
		}
		temp = temp->next;
	}
	return (1);
}

int	ft_export(t_env *env, t_token *arg, t_mem *mem)
{
	t_token	*temp;
	int		i;

	temp = arg->next;
	i = 0;
	if (is_end_command(temp))
		return (ft_print_export(env));
	while (!is_end_command(temp))
	{
		if (is_valid_for_export(temp->value))
		{
			add_env(temp->value, &env);
			add_env(temp->value, &(mem->my_env));
		}
		else
		{
			printf("minishell: export: '%s': not a valid identifier\n",
				temp->value);
			i = 1;
		}
		temp = temp->next;
	}
	mem->exit_stat = i;
	return (1);
}
