/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:14:30 by davli             #+#    #+#             */
/*   Updated: 2024/05/16 18:38:50 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (len)
	{
		len--;
		str[len] = c;
	}
	return (s);
}
/*
#include <stdio.h>
int	main()
{
	int	i = 0;
	char	tab[5];
	ft_memset(tab, 's', 5);
	while (i < 5)
	{
		printf("%c", tab[i]);
		i++;
	}
}
*/