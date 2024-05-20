/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:02:37 by davli             #+#    #+#             */
/*   Updated: 2024/05/20 19:36:39 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		alpha;

	i = 0;
	count = 0;
	alpha = 0;
	while (s[i])
	{
		if (s[i] == c && alpha == 1)
		{
			count++;
			alpha = 0;
		}
		else if (s[i] != c)
			alpha = 1;
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static void	fill_tab(char *tab, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
}

static void	make_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j > 0)
		{
			tab[k] = malloc(sizeof(char) * j + 1);
			if (!tab[k])
				return ;
			fill_tab(tab[k], (s + i), c);
			k++;
			i = i + j;
		}
		else
			i++;
	}
	tab[k] = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**tab;

	words = count_words(s, c);
	tab = malloc(sizeof(char *) * words + 1);
	if (!tab)
		return (NULL);
	make_tab(tab, s, c);
	return (tab);
}
/*
int	main()
{
	char	**tab;
	int	i;

	i = 0;
	tab = ft_split("        Yo tout le monde c'est   squeezie          ", ' ');
	while (i < 6)
	{
		printf("%s\n", tab[i++]);
	}
}
*/
