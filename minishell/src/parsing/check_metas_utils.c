/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_metas_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:15:08 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/07 16:53:15 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_meta_char(char *s)
{
	if (!ft_strcmp(s, "<"))
		return (REDIRECT_IN);
	if (!ft_strcmp(s, ">"))
		return (REDIRECT_OUT);
	if (!ft_strcmp(s, "<<"))
		return (HEREDOC);
	if (!ft_strcmp(s, ">>"))
		return (APPEND);
	if (!ft_strcmp(s, "&&"))
		return (AND);
	if (!ft_strcmp(s, "||"))
		return (OR);
	if (!ft_strcmp(s, "|"))
		return (PIPE);
	return (0);
}

int	is_redirect(char *s)
{
	if (!ft_strcmp(s, "<"))
		return (REDIRECT_IN);
	if (!ft_strcmp(s, ">"))
		return (REDIRECT_OUT);
	if (!ft_strcmp(s, "<<"))
		return (HEREDOC);
	if (!ft_strcmp(s, ">>"))
		return (APPEND);
	return (0);
}

int	is_logical(char *s)
{
	if (!ft_strcmp(s, "&&"))
		return (AND);
	if (!ft_strcmp(s, "||"))
		return (OR);
	return (0);
}

int	is_end_command(t_token *arg)
{
	if (!arg)
		return (42);
	if (!ft_strcmp(arg->value, "&&"))
		return (AND);
	if (!ft_strcmp(arg->value, "||"))
		return (OR);
	if (!ft_strcmp(arg->value, "|"))
		return (PIPE);
	return (0);
}

void	increase_i_j(int *i, int *j)
{
	(*i)++;
	(*j)++;
}
