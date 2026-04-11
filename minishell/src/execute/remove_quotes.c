/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:32:02 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/11 17:38:23 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	nnext_quote(char *s)
{
	size_t	sq;
	size_t	dq;

	sq = ft_strchr(s, '\'');
	dq = ft_strchr(s, '"');
	if (sq < dq)
		return (1);
	else if (dq < sq)
		return (2);
	else
		return (0);
}

static size_t	get_n(char *str, size_t i)
{
	size_t	n;

	if (str[i] == '\'')
		n = ft_strchr(str + i + 1, '\'');
	else if (str[i] == '"')
		n = ft_strchr(str + i + 1, '"');
	else
	{
		if (nnext_quote(str + i) == 1)
			n = ft_strchr(str + i, '\'');
		else
			n = ft_strchr(str + i, '"');
	}
	return (n);
}

char	*remove_quotes(char *str, t_env *env, t_mem *mem)
{
	size_t	i;
	size_t	n;
	char	*s;
	char	*sub;

	i = 0;
	s = ft_strdup("");
	while (str[i])
	{
		n = get_n(str, i);
		if (str[i] == '\'' || str[i] == '"')
		{
			if (str[i] == '\'')
				sub = ft_substr(str + i, 1, n);
			if (str[i] == '"')
				sub = expansion(ft_substr(str + i, 1, n), env, mem);
			i += 2;
		}
		else
			sub = expansion(ft_substr(str + i, 0, n), env, mem);
		s = my_strjoin(s, sub);
		i += n;
		free(sub);
	}
	return (free(str), s);
}
