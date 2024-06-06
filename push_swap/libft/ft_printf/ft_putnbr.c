/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:21:04 by davli             #+#    #+#             */
/*   Updated: 2024/05/27 19:54:31 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	real_putnbr(int n)
{
	long	nb;

	nb = (long)n;
	if (n < 0)
	{	
		nb = -nb;
		ft_putchar('-');
	}
	if (nb >= 10)
		real_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

size_t	ft_putnbr(int n)
{
	size_t	i;
	long	nb;

	i = 0;
	nb = (long)n;
	if (n <= 0)
		i++;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	real_putnbr(n);
	return (i);
}
