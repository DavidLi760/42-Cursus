/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:56:53 by davli             #+#    #+#             */
/*   Updated: 2024/05/13 14:02:15 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdio.h>
int	main()
{
	int	a;
	int	b;
	int	*div = &a;
	int	*mod = &b;

	a = 50;
	b = 42;
	ft_div_mod(a, b, div, mod);
	printf("%d, %d", a, b);
}
*/
