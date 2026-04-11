/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:44:17 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/24 12:56:43 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_remnant(char *remnant, char *readed)
{
	size_t	pos;
	size_t	len;

	if (*remnant)
	{
		pos = gnl_strchr(remnant);
		len = gnl_strlen(remnant);
		if (pos < len)
		{
			gnl_strlcpy(readed, remnant, pos + 1);
			gnl_strlcpy(remnant, remnant + pos + 1, len - pos - 1);
			return (1);
		}
		else
			gnl_strlcpy(readed, remnant, len);
	}
	return (0);
}

void	update_readed(char **readed, char *new)
{
	char	*temp;
	size_t	readlen;
	size_t	newlen;

	readlen = gnl_strlen(*readed);
	newlen = gnl_strlen(new);
	if (readlen == 0)
		gnl_strlcpy(*readed, new, newlen);
	else
	{
		temp = malloc(readlen + newlen + 1);
		if (!temp)
			return ;
		gnl_strlcpy(temp, *readed, readlen);
		gnl_strlcpy(temp + readlen, new, newlen);
		free(*readed);
		*readed = temp;
	}
}

void	read_file(int fd, char *cur, char **readed, char *remnant)
{
	char	*new;
	size_t	bytes_read;
	size_t	pos;

	bytes_read = read(fd, cur, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		cur[bytes_read] = 0;
		pos = gnl_strchr(cur);
		if (pos < bytes_read)
		{
			new = gnl_substr(cur, 0, pos + 1);
			if (!new)
				return ;
			update_readed(readed, new);
			free(new);
			gnl_strlcpy(remnant, cur + pos + 1, gnl_strlen(cur) - pos);
			break ;
		}
		else
			update_readed(readed, cur);
		bytes_read = read(fd, cur, BUFFER_SIZE);
	}
	if (bytes_read == 0)
		remnant[0] = 0;
}

char	*get_next_line(int fd)
{
	char		*cur;
	char		*readed;
	static char	remnant[BUFFER_SIZE + 1];

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	cur = malloc(BUFFER_SIZE + 1);
	if (!cur)
		return (NULL);
	cur[0] = 0;
	readed = malloc(BUFFER_SIZE + 1);
	if (!readed)
		return (free(cur), NULL);
	readed[0] = 0;
	if (check_remnant(remnant, readed))
		return (free(cur), readed);
	read_file(fd, cur, &readed, remnant);
	free(cur);
	if (gnl_strlen(readed) == 0)
		return (free(readed), NULL);
	return (readed);
}
