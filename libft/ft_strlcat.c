/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:53:43 by davli             #+#    #+#             */
/*   Updated: 2024/05/17 19:39:49 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	startlen;
	size_t	retlen;

	startlen = 0;
	while (startlen < len && dest[startlen])
		startlen++;
	retlen = ft_strlen(src) + startlen;
	dest += startlen;
	if (len != startlen)
	{
		while (*src)
		{
			if (len > startlen + 1)
			{
				*dest++ = *src;
				len--;
			}
			src++;
		}
		*dest = 0;
	}
	return (retlen);
}
/*
int main() 
{
    char dest[20] = "Hello, ";
    char src[] = "World!";

    size_t total_len = ft_strlcat(dest, src, sizeof(dest));

    printf("Chaîne résultante : %s\n", dest);
    printf("Longueur totale : %zu\n", total_len);

    return 0;
}
*/
