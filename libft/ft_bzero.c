/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:59:51 by davli             #+#    #+#             */
/*   Updated: 2024/05/22 20:48:00 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n != 0)
	{
		n--;
		str[n] = '\0';
	}
}
/*
#include <stdio.h>
int     main()
{
        int     i = 0;
        char    tab[5];
	ft_bzero(tab, 5);
        while (i < 5)
        {
                printf("%c", tab[i]);
                i++;
        }
}
*/
