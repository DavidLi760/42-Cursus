/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:53:35 by davli             #+#    #+#             */
/*   Updated: 2024/05/17 19:26:22 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (len != 0 && i < len - 1 && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	if (i < len)
		dest[i] = 0;
	while (src[i])
		++i;
	return (i);
}
/*
int main() {
    char src[] = "123456789123456789!";
    char dest[20];

    size_t len_copied = ft_strlcpy(dest, src, sizeof(dest));

    printf("Chaîne copiée : %s\n", dest);
    printf("Nombre de caractères copiés : %zu\n", len_copied);

    return 0;
}
*/
