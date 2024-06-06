/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:53:09 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 17:43:18 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n)
	{
		n--;
		d[n] = s[n];
	}
	return (dest);
}
/*
int main()
{
    char src[] = "Yo tout le monde c'est";
    char dst[20];
    ft_memcpy(dst, src, strlen(src) + 1);
    printf("ft_memcpy: %s\n", dst);
    return 0;
}
*/
