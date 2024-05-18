/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:20:36 by davli             #+#    #+#             */
/*   Updated: 2024/05/18 19:20:37 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;
	size_t			i;

	first = (unsigned char *)s1;
	second = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (first[i] != second[i])
			return (first[i] - second[i]);
		++i;
	}
	return (0);
}
