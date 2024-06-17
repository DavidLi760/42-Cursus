/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:19:28 by davli             #+#    #+#             */
/*   Updated: 2024/06/17 17:58:50 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

static int	no_double(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (j != i && nbrcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!is_number(av[i]))
			return (0);
		i++;
	}
	if (no_double(av) == 1)
		return (0);
	return (1);
}
