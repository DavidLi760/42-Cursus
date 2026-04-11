/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:48:16 by xiaxu             #+#    #+#             */
/*   Updated: 2024/05/17 16:28:05 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nl;
	char	*result;

	len = nbr_len(n);
	nl = n;
	if (n < 0)
		nl = -nl;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = 0;
	if (nl == 0)
		result[0] = '0';
	else
	{
		while (nl)
		{
			result[--len] = nl % 10 + '0';
			nl = (nl - (nl % 10)) / 10;
		}
		if (n < 0)
			result[0] = '-';
	}
	return (result);
}
