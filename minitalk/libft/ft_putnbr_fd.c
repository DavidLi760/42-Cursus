/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:46:33 by davli             #+#    #+#             */
/*   Updated: 2024/05/24 17:07:01 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t	nbr;

	nbr = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}
/*
int     main(int argc, char **argv)
{
	if (argc < 1)
		return (0);
	int	fd;
	fd = open(argv[2], O_RDWR);
	ft_putnbr_fd(atoi(argv[1]), fd);
	close(fd);
}
*/
