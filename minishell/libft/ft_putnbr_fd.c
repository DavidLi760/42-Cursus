/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:50:55 by xiaxu             #+#    #+#             */
/*   Updated: 2024/05/17 15:50:56 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nl;

	nl = n;
	if (nl < 0)
	{
		ft_putchar_fd('-', fd);
		nl = -nl;
	}
	if (nl / 10 > 0)
	{
		ft_putnbr_fd(nl / 10, fd);
		ft_putchar_fd((nl % 10) + '0', fd);
	}
	else
		ft_putchar_fd((nl % 10) + '0', fd);
}
