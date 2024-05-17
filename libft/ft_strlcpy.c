/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:53:35 by davli             #+#    #+#             */
/*   Updated: 2024/05/17 18:37:00 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (dstsize != 0 && i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	if (i < dstsize)
		dst[i] = 0;
	while (src[i])
		++i;
	return (i);
}
