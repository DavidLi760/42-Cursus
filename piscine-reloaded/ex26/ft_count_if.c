/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:44:06 by davli             #+#    #+#             */
/*   Updated: 2024/05/14 16:28:56 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}
/*
#include <stdio.h>
int	if_a(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a' || str[i] == 'A')
			return (1);
	}
	return (0);
}
int	main()
{
	int	i = 0;
	char	tab = {
		{"SALUT", "YO"}
		{"H OUI", "NON"}
	};
	while (i < 3)
	{
		printf("%d, ", ft_count_if(tab, if_a));
	}
}
*/
