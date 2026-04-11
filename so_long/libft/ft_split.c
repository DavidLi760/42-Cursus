/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:02:37 by davli             #+#    #+#             */
/*   Updated: 2024/06/25 15:39:02 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	fill_tab(char *new, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
}

static char	**make_tab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (s[j])
	{
		i = 0;
		while (s[j + i] && s[j + i] != c)
			i++;
		if (i > 0)
		{
			tab[k] = malloc(sizeof(char) * (i + 1));
			if (!tab[k])
				return (NULL);
			fill_tab(tab[k], (s + j), c);
			k++;
			j = j + i;
		}
		else
			j++;
	}
	tab[k] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**tab;

	words = count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	make_tab(tab, s, c);
	return (tab);
}
/*
int	main()
{
	int i = 0;
	char *str;
	char **tab;

	str = "\n\n\n";
	tab = ft_split(str, '\n');
	while (tab[i])
		printf("%s\n", tab[i++]);
}
*/
