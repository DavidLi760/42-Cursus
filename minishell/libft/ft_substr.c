/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:53:38 by xiaxu             #+#    #+#             */
/*   Updated: 2024/08/20 14:29:45 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		sub = ft_calloc(1, 1);
		if (!sub)
			return (NULL);
	}
	else
	{
		i = ft_strlen(s + start);
		if (i > len)
			i = len;
		sub = malloc(i + 1);
		if (!sub)
			return (NULL);
		sub[i] = 0;
		while (i-- > 0)
			sub[i] = s[start + i];
	}
	return (sub);
}
