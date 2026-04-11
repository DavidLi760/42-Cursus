/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:36:30 by xiaxu             #+#    #+#             */
/*   Updated: 2024/09/11 14:31:38 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*my_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	if (s1)
		ft_strlcpy(res, s1, len1 + 1);
	if (s2)
		ft_strlcpy((res + len1), s2, len2 + 1);
	if (s1)
		free(s1);
	return (res);
}

int	open_here_doc(void)
{
	int	fd;

	fd = open(".here_doc.tmp", O_RDONLY);
	if (fd == -1)
	{
		unlink(".here_doc.tmp");
		perror(".here_doc.tmp file open failure");
	}
	return (fd);
}

int	open_file(char *file, int n, t_mem *mem)
{
	int	fd;

	if (n == REDIRECT_IN)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			perror("Infile open failure");
	}
	else if (n == REDIRECT_OUT)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		if (fd == -1)
			perror("Outfile open failure");
	}
	else if (n == APPEND)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
		if (fd == -1)
			perror("Outfile open failure");
	}
	else
		fd = get_here_doc_input(file, mem);
	return (fd);
}

char	**get_paths(t_env *env)
{
	char	*s;
	char	**paths;

	s = ft_strdup(my_getenv("PATH", env));
	if (!s)
		return (NULL);
	paths = ft_split(s, ':');
	free(s);
	if (!paths)
		return (NULL);
	return (paths);
}

char	*get_command(char **paths, char *cmd)
{
	int		i;
	char	*try;
	char	*command;

	i = 0;
	if (is_builtins(cmd))
		return (ft_strdup(cmd));
	while (paths[i])
	{
		try = ft_strjoin(paths[i], "/");
		command = ft_strjoin(try, cmd);
		free(try);
		if (!command)
			return (NULL);
		if (access(command, 1) == 0)
			return (command);
		free(command);
		i++;
	}
	if (access(cmd, 1) == 0)
		return (ft_strdup(cmd));
	perror("Command not found");
	return (NULL);
}
