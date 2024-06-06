/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:15:37 by davli             #+#    #+#             */
/*   Updated: 2024/05/21 20:11:42 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	str = ft_strdup(s);
	if (!s || !str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
/*
int main() 
{
	char	to_alternate_case(unsigned int i, char c)
	{
		if (i % 2 == 0)
			return ft_tolower(c);
		else
			return ft_toupper(c);
	}
	char	str[] = "HeLLo WoRLd!";
	char	*result = ft_strmapi(str, to_alternate_case);

	if (result)
	{
		printf("Original: %s\n", str);
		printf("Modified: %s\n", result);
		free(result);
	}
	return 0;
}
*/
