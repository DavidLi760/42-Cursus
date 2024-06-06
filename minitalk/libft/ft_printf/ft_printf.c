/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:28:23 by davli             #+#    #+#             */
/*   Updated: 2024/05/29 15:16:25 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	str_format(const char *str, size_t *i, va_list *ap)
{
	*i = *i + 1;
	if (str[*i] == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (str[*i] == 's')
		return (ft_putstr(va_arg(*ap, const char *)));
	else if (str[*i] == 'p')
		return (ft_printmem(va_arg(*ap, void *)));
	else if (str[*i] == 'd' || str[*i] == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (str[*i] == 'u')
		return (ft_putunsigned(va_arg(*ap, unsigned int)));
	else if (str[*i] == 'x')
		return (ft_puthex_lower(va_arg(*ap, unsigned int)));
	else if (str[*i] == 'X')
		return (ft_puthex_upper(va_arg(*ap, unsigned int)));
	else if (str[*i] == '%')
		return (ft_putchar('%'));
	else
	{
		*i = *i - 1;
		return (-1);
	}
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		stock;
	va_list	ap;
	size_t	i;

	if (!str)
		return (-1);
	va_start(ap, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			stock = str_format(str, &i, &ap);
		else
			stock = ft_putchar(str[i]);
		if (stock >= 0)
			len += stock;
		else
			len = stock;
		i++;
	}
	va_end(ap);
	return (len);
}
/*
int	main()
{
//	int	lol = 0;

//	printf("%d\n", printf("%d", LONG_MAX));
	ft_printf("r:%d", ft_printf("v:%d", LONG_MIN));
	return (0);
}
*/
