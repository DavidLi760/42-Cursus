/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:50:31 by davli             #+#    #+#             */
/*   Updated: 2024/05/18 19:00:32 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		if (++i >= n)
			break ;
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*
int main(void)
{
    char *str1 = "Hello, world!";
    char *str2 = "Hello, 42!";
    int result = ft_strncmp(str1, str2, 8);
    printf("Comparison result: %d\n", result);
    return 0;
}
*/
