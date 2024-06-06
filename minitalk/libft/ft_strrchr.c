/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:01:23 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 18:34:37 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s1;

	s1 = (char *)s;
	i = ft_strlen(s) + 1;
	while (i--)
		if (s1[i] == (char)c)
			return ((char *)s1 + i);
	return (NULL);
}
/*
int	main()
{
	printf("%s\n", ft_strrchr("Salut tu vas bien?", 't'));
}
*/
