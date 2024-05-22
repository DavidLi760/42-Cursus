/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:51:22 by davli             #+#    #+#             */
/*   Updated: 2024/05/22 20:01:33 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == 0)
		return ((char *)(big));
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while ((i + j) < len && little[j] == big[i + j])
		{
			j++;
			if (little[j] == 0)
				return ((char *)(big + i));
		}
		++i;
	}
	return (NULL);
}
/*
int	main()
{
	char	str1[] = "T'aime le chocolat noir? je prefere les blancs";
	char	str2[] = "je";

	printf("%s", ft_strnstr(str1, str2, 27));
}
*/
