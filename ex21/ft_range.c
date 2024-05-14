/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:44:43 by davli             #+#    #+#             */
/*   Updated: 2024/05/14 16:29:25 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*array;

	i = 0;
	if (min >= max)
		return (NULL);
	size = max - min;
	array = malloc(size * sizeof(int));
	if (!array)
		return (0);
	while (min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}
/*
#include <stdio.h>
int	main()
{
	int	min = 1;
	int	max = 500;
	int	*tab;
	int	i = 0;

	tab = ft_range(min, max);
	while (i < max - min)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}
*/
