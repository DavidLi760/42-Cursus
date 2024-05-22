/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:14:30 by davli             #+#    #+#             */
/*   Updated: 2024/05/22 21:01:05 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	while (n)
	{
		n--;
		str[n] = c;
	}
	return ((void *)str);
}
/*
#include <stdio.h>
int	main()
{
	int	i = 0;
	char	tab[5];
	ft_memset(tab, 'A', 5);
	while (i < 5)
	{
		printf("%c", tab[i]);
		i++;
	}
}
*/
