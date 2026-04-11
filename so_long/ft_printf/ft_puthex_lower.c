/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:01:47 by davli             #+#    #+#             */
/*   Updated: 2024/05/27 19:18:47 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthex_lower(unsigned int n)
{
	if (n / 16)
		return (ft_puthex_lower(n / 16) + ft_puthex_lower(n % 16));
	else if (!(n / 10))
		ft_putchar(n + '0');
	else
		ft_putchar(n - 10 + 'a');
	return (1);
}
