/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:53:43 by davli             #+#    #+#             */
/*   Updated: 2024/05/17 18:36:42 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	startlen;
	size_t	retlen;

	startlen = 0;
	while (startlen < dstsize && dst[startlen])
		startlen++;
	retlen = ft_strlen(src) + startlen;
	dst += startlen;
	if (dstsize != startlen)
	{
		while (*src)
		{
			if (dstsize > startlen + 1)
			{
				*dst++ = *src;
				dstsize--;
			}
			src++;
		}
		*dst = 0;
	}
	return (retlen);
}
