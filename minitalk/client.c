/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:19:28 by jotavare          #+#    #+#             */
/*   Updated: 2024/06/06 11:18:16 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char *str)
{
	int	i;
	int	c;

	i = 0;
	while (*str)
	{
		c = *(str);
		while (i < 8)
		{
			if (c << i & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(10);
		}
		str++;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error ./client <PID> <STRING>\n");
		return (0);
	}
	else
	{
		send_signal(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}
