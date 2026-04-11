/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:52:24 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/11 16:17:46 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ps_atoi(char *str, int *check)
{
	long	result;
	int		sign;
	size_t	i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if ((sign == 1 && (result > (INT_MAX - str[i] + '0') / 10))
			|| (sign == -1 && (result * sign < (INT_MIN + str[i] - '0') / 10)))
		{
			*check = 1;
			return (2);
		}
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

static int	regular(int num)
{
	while (num < 0)
		num += 256;
	while (num >= 256)
		num -= 256;
	return (num);
}

static void	deal_exit(int *n, char *s, t_mem *mem)
{
	int	i;
	int	num;
	int	check;

	i = -1;
	check = 0;
	*n = 1;
	while (s[++i])
	{
		if ((s[i] > '9' || s[i] < '0')
			&& !(i == 0 && (s[i] == '+' || s[i] == '-')))
			check = 1;
	}
	num = ps_atoi(s, &check);
	if (check)
	{
		ft_putstr_fd("minishell: exit: : numeric argument required\n", 2);
		mem->exit_stat = 2;
		return ;
	}
	mem->exit_stat = regular(num);
}

int	ft_exit(t_token *arg, t_mem *mem)
{
	t_token	*temp;
	int		n;

	temp = arg->next;
	n = 0;
	while (!is_end_command(temp))
	{
		if ((temp->type == ARGUMENT) && n == 0)
			deal_exit(&n, temp->value, mem);
		else if ((temp->type == ARGUMENT) && n == 0)
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			mem->exit_stat = 1;
			return (0);
		}
		temp = temp->next;
	}
	if (mem->pipe_num == 0)
		mem->exit = 1;
	return (1);
}
