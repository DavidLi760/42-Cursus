/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:49:02 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 18:14:05 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
		if (str[i++] == (unsigned char)c)
			return (str + i - 1);
	return (NULL);
}
/*
int main(void)
{
    const char str[] = "Hello, world!";
    int c = 'o';
    char *result = ft_memchr(str, c, 5);

    if (result)
        printf("Character '%c' found at position: %ld\n", c, result - str);
    else
        printf("Character '%c' not found.\n", c);

    return 0;
}
*/
