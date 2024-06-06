/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:50:42 by davli             #+#    #+#             */
/*   Updated: 2024/05/28 10:56:06 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	real_putunsigned(unsigned int n)
{
	unsigned long	nb;

	nb = (long)n;
	if (nb >= 10)
		real_putunsigned(nb / 10);
	ft_putchar(nb % 10 + '0');
}

size_t	ft_putunsigned(unsigned int n)
{
	size_t			i;
	unsigned int	nb;

	nb = (long)n;
	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (nb)
	{
		i++;
		nb /= 10;
	}
	real_putunsigned(n);
	return (i);
}
