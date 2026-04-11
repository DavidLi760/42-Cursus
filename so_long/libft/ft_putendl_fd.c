/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:41:36 by davli             #+#    #+#             */
/*   Updated: 2024/05/22 16:44:20 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}
/*
int	main(int argc, char **argv)
{
	if (argc < 1)
                return (0);
        int     fd;
        fd = open(argv[2], O_RDWR);
        ft_putendl_fd(argv[1], fd);
        close(fd);
}
*/
