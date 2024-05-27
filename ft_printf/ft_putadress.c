/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:18:24 by davli             #+#    #+#             */
/*   Updated: 2024/05/27 11:18:26 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	printadress(const unsigned long n)
{
	if (n / 16)
		return (printadress(n / 16) + printadress(n % 16));
	else if (!(n / 10))
		ft_putchar(n + '0');
	else
		ft_putchar((char) n - 10 + 'a');
	return (1);
}

size_t	ft_putadress(void *adress)
{
	if (!adress)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + printadress((unsigned long) adress));
}
