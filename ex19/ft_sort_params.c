/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:17:38 by davli             #+#    #+#             */
/*   Updated: 2024/05/14 16:04:13 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print_params(char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i] != 0)
	{
		while (argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}

void	ft_sort_params(char **argv)
{
	int		i;
	char	*stock;

	i = 1;
	while (argv[i + 1])
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			stock = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = stock;
			i = 0;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		while (argv[1][i])
		{
			ft_putchar(argv[1][i]);
			i++;
		}
		ft_putchar('\n');
		return (0);
	}
	ft_sort_params(argv);
	ft_print_params(argv);
}
