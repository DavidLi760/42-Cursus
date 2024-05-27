/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:17:30 by davli             #+#    #+#             */
/*   Updated: 2024/05/27 11:17:57 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	print_nb(long nb)
{
	if (nb / 10)
		return (print_nb(nb / 10) + print_nb(nb % 10));
	else
		return (ft_putchar(nb + '0'));
}

size_t	ft_putnbr(const int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		return (ft_putchar('-') + print_nb(nb));
	}
	else
		return (print_nb(nb));
}
