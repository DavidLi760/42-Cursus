/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:53:43 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 18:23:37 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	dstlen;
	size_t	retlen;

	dstlen = 0;
	while (dstlen < len && dest[dstlen])
		dstlen++;
	retlen = ft_strlen(src) + dstlen;
	dest += dstlen;
	if (len != dstlen)
	{
		while (*src)
		{
			if (len - 1 > dstlen)
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
    char dest[20] = "Hello ";
    char src[] = "World!";

    size_t total_len = ft_strlcat(dest, src, 13);

    printf("Chaîne résultante : %s\n", dest);
    printf("Longueur totale : %zu\n", total_len);

    return 0;
}
*/
