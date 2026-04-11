/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:53:32 by xiaxu             #+#    #+#             */
/*   Updated: 2024/05/17 15:53:33 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*empty_string(void)
{
	char	*s;

	s = malloc(1);
	if (!s)
		return (NULL);
	s[0] = 0;
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	size_t	len;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	begin = 0;
	while (is_set(s1[begin], set))
		begin++;
	len = ft_strlen(s1);
	if (begin == len)
		return (empty_string());
	end = len - 1;
	while (is_set(s1[end], set))
		end--;
	res = malloc(end - begin + 2);
	if (!res)
		return (NULL);
	ft_strlcpy(res, (s1 + begin), (end - begin + 2));
	return (res);
}
