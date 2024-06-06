/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:12:14 by davli             #+#    #+#             */
/*   Updated: 2024/05/29 13:59:14 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	printaddress(unsigned long n)
{
	if (n / 16)
		return (printaddress(n / 16) + printaddress(n % 16));
	else if (!(n / 10))
		ft_putchar(n + '0');
	else
		ft_putchar(n - 10 + 'a');
	return (1);
}

size_t	ft_printmem(void *address)
{
	if (!address)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + printaddress((unsigned long) address));
}
