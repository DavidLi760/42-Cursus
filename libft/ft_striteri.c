/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:50:54 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 14:43:49 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		++i;
	}
}
/*
void to_uppercase(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
    {
        *c = *c - ('a' - 'A');
    }
}

int main()
{
    char str[] = "hello world!";

    printf("Original string: %s\n", str);
    ft_striteri(str, to_uppercase);
    printf("Modified string: %s\n", str);

    return 0;
}
*/
