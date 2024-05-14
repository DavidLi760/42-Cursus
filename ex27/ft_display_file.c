/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:36:31 by davli             #+#    #+#             */
/*   Updated: 2024/05/14 17:10:18 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>

int	ft_display_file(char *file)
{
	int		file;
	int		read;
	char	*stock;

	file = open(file, O_RDONLY);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else if (!ft_display_file(argv[1]))
		write(2, "Cannot read file.\n", 18);
	return (0);
}
