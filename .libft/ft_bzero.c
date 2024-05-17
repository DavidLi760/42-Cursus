/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:59:51 by davli             #+#    #+#             */
/*   Updated: 2024/05/16 18:38:09 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_bzero(void *s, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (len != 0)
	{
		len--;
		str[len] = '\0';
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
