/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:17:03 by xiaxu             #+#    #+#             */
/*   Updated: 2024/08/28 14:46:50 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	index_n(char *s, char *c, int n)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_strncmp(s + i, c, ft_strlen(c)))
			n--;
		if (n <= 0)
			return (i);
		i++;
	}
	return (i);
}

size_t	next_quote(char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '"')
			break ;
		i++;
	}
	while (s[j])
	{
		if (s[j] == '\'')
			break ;
		j++;
	}
	if (i > j)
		i = j;
	return (i);
}

static int	set_quotes_n(char c, int *quotes_n)
{
	int	cquotes;

	cquotes = *quotes_n;
	if (c == '\'')
	{
		if (cquotes == 0)
			*quotes_n = 1;
		else if (cquotes == 1)
			*quotes_n = 0;
	}
	if (c == '"')
	{
		if (cquotes == 0)
			*quotes_n = 2;
		else if (cquotes == 2)
			*quotes_n = 0;
	}
	return (cquotes);
}

int	check_quotes(char *s)
{
	int	i;
	int	quote_n;

	i = 0;
	quote_n = 0;
	while (s[i])
	{
		set_quotes_n(s[i], &quote_n);
		i++;
	}
	if (quote_n != 0)
		return (printf("minishell: invalid input: quotes not closed\n"), 0);
	return (1);
}
