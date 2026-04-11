/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:40:54 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/01 15:57:38 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(const char c, const char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			break ;
		i++;
	}
	if (base[i])
		return (i);
	else
		return (-1);
}

unsigned int	ft_atoi_base(const char *str, const char *base)
{
	unsigned int	num;
	unsigned int	base_len;
	unsigned int	i;

	num = 0;
	base_len = ft_strlen(base);
	i = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (ft_strncmp(str + i, "0x", 2) == 0
		&& ft_strncmp(base, "0123456789ABCDEF", 16) == 0)
		str += 2;
	while (str[i])
	{
		if (check_base(ft_toupper(str[i]), base) >= 0)
			num = num * base_len + check_base(ft_toupper(str[i]), base);
		else
			break ;
		i++;
	}
	return (num);
}
