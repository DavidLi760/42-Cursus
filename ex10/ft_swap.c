/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:51:35 by davli             #+#    #+#             */
/*   Updated: 2024/05/13 13:56:29 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	stock;

	stock = *a;
	*a = *b;
	*b = stock;
}
/*
#include <stdio.h>
int	main()
{
	int	a = 42;
	int	b = 2;
	ft_swap(&a, &b);
	printf("%d, %d", a, b);
}
*/