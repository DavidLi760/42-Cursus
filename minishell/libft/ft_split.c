/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:51:12 by xiaxu             #+#    #+#             */
/*   Updated: 2024/08/20 17:21:05 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	split_into_words(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i] && j < (unsigned int)count_word(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			result[j][k++] = s[i++];
		}
		result[j][k] = 0;
		j++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	size_t	word_len;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_word(s, c);
	res = malloc((word_count + 1) * sizeof (char *));
	if (!res)
		return (NULL);
	i = 0;
	word_len = ft_strlen(s) + 1;
	while (i < word_count)
	{
		res[i] = malloc(word_len);
		if (!res[i])
			return (NULL);
		i++;
	}
	res[i] = 0;
	if (word_count)
		split_into_words(res, s, c);
	return (res);
}
