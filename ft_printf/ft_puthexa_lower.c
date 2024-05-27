/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:16:25 by davli             #+#    #+#             */
/*   Updated: 2024/05/27 11:16:28 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthexa_lower(const unsigned int n)
{
	if (n / 16)
		return (ft_puthexa_lower(n / 16) + ft_puthexa_lower(n % 16));
	else if (!(n / 10))
		ft_putchar(n + '0');
	else
		ft_putchar((char) n - 10 + 'a');
	return (1);
}
