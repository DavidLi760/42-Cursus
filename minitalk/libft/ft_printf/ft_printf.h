/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:39:39 by davli             #+#    #+#             */
/*   Updated: 2024/05/29 15:14:59 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
size_t	ft_putchar(const char c);
size_t	ft_putstr(const char *str);
size_t	ft_printmem(void *adress);
size_t	ft_putnbr(int n);
size_t	ft_putunsigned(unsigned int n);
size_t	ft_puthex_lower(unsigned int n);
size_t	ft_puthex_upper(unsigned int n);

#endif
