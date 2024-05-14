/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:08:20 by davli             #+#    #+#             */
/*   Updated: 2024/05/14 14:43:32 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nb2;

	nb2 = nb;
	if (nb2 < 0)
	{
		ft_putchar('-');
		nb2 = -nb2;
	}
	else if (nb2 >= 10)
	{
		ft_putnbr(nb2 / 10);
		ft_putnbr(nb2 % 10);
	}
	else
		ft_putchar(nb2 + '0');
}

int	main()
{
	int	tab[] = {525, 685445, 2147483647};
	ft_foreach(tab, 3, &ft_putnbr);
}
*/
