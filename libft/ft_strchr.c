/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:48:36 by davli             #+#    #+#             */
/*   Updated: 2024/05/22 19:44:01 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	while (1)
	{
		if (s1[i] == c)
			return (s1 + i);
		else if (s1[i] == 0)
			break ;
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	printf("%s\n", ft_strchr("Salut tu vas bien", 't'));
}
*/
