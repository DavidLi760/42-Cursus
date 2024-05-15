/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:37:20 by davli             #+#    #+#             */
/*   Updated: 2024/05/14 15:25:23 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*dup;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	dup = malloc(size * sizeof(char) + 1);
	if (!dup)
		return (0);
	while (i < size)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>
int	main()
{
	char	*src = "Yo tout le monde c'est Squeezie";

	printf("%s", ft_strdup(src));
}
*/
