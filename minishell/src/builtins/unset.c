/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:27:23 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/08 02:13:52 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*my_getenv(char *key, t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		if (!ft_strcmp(temp->key, key) && temp->is_unset != 1)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

static int	is_valid_for_unset(char *s, t_mem *mem)
{
	int	i;
	int	valid;

	valid = 1;
	if (!ft_isalpha(s[0]) && s[0] != '_')
		valid = 0;
	i = 0;
	while (s[i])
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
			valid = 0;
		i++;
	}
	if (!valid)
	{
		mem->exit_stat = 1;
		printf("minishell: unset: '%s': not a valid identifier\n", s);
	}
	else
		mem->exit_stat = 0;
	return (1);
}

static void	check_valid_unset(t_token *list, t_mem *mem)
{
	t_token	*temp;

	temp = list;
	while (temp && !is_end_command(temp))
	{
		is_valid_for_unset(temp->value, mem);
		temp = temp->next;
	}
}

int	ft_unset(t_env *my_env, t_env *values, t_token *arg, t_mem *mem)
{
	t_env	*temp_env;
	t_env	*temp_val;
	t_token	*temp;

	temp = arg->next;
	check_valid_unset(temp, mem);
	while (temp && !is_end_command(temp))
	{
		temp_env = my_env;
		temp_val = values;
		while (temp_env)
		{
			if (!ft_strcmp(temp_env->key, temp->value))
				temp_env->is_unset = 1;
			temp_env = temp_env->next;
		}
		while (temp_val)
		{
			if (!ft_strcmp(temp_val->key, temp->value))
				temp_val->is_unset = 1;
			temp_val = temp_val->next;
		}
		temp = temp->next;
	}
	return (0);
}
