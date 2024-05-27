/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:16:45 by davli             #+#    #+#             */
/*   Updated: 2024/05/27 11:16:50 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthexa_upper(const unsigned int n)
{
	if (n / 16)
		return (ft_puthexa_upper(n / 16) + ft_puthexa_upper(n % 16));
	else if (!(n / 10))
		ft_putchar(n + '0');
	else
		ft_putchar((char) n - 10 + 'A');
	return (1);
}
