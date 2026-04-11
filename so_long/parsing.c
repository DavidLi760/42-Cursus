/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:33:57 by davli             #+#    #+#             */
/*   Updated: 2024/06/29 18:35:31 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_opening(char *argv, t_vars *vars)
{
	int	len;

	len = 0;
	len = ft_strlen(argv);
	if (len < 4)
		return (0);
	if (ft_strcmp(&argv[len - 4], ".ber") != 0)
		return (0);
	vars->map_fd = open(argv, O_RDONLY);
	if (vars->map_fd < 0)
		return (0);
	return (1);
}

int	check_rectangular(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->map_width = 0;
	if (!vars->map_line[0])
		return (0);
	while (vars->map_line[i][vars->map_width])
		vars->map_width++;
	if (vars->map_width > 29)
		return (0);
	while (vars->map_line[i])
	{
		j = 0;
		while (vars->map_line[i][j])
			j++;
		if (vars->map_width != j)
			return (0);
		i++;
	}
	if (i > 15)
		return (0);
	return (1);
}

int	is_closed(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->map_height = 0;
	while (vars->map_line[vars->map_height])
		vars->map_height++;
	while (vars->map_line[i])
	{
		j = 0;
		if (vars->map_line[0][j] != '1' ||
				vars->map_line[vars->map_height - 1][j] != '1')
			return (0);
		while (vars->map_line[i][j])
		{
			if (vars->map_line[i][0] != '1' ||
					vars->map_line[i][vars->map_width - 1] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	get_map_pos(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map_line[i])
	{
		j = 0;
		while (vars->map_line[i][j])
		{
			if (vars->map_line[i][j] == 'P')
			{
				vars->p_pos.x = i;
				vars->p_pos.y = j;
			}
			if (vars->map_line[i][j] == 'E')
			{
				vars->e_pos.x = i;
				vars->e_pos.y = j;
			}
			j++;
		}
		i++;
	}
}

void	map_error(t_vars *vars)
{
	if (!check_rectangular(vars))
		exit_error(-9, vars);
	if (!is_closed(vars))
		exit_error(-8, vars);
	if (!check_correct_char(vars))
		exit_error(-7, vars);
	get_map_pos(vars);
	if (!flood_fill(vars))
		exit_error(-6, vars);
}
/*
int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.map_fd = open(argv[1], O_RDONLY);
	vars.map_buf = get_next_line(vars.map_fd);
	if (!vars.map_buf)
		return (0);
	vars.map_line = ft_split(vars.map_buf, '\n');
	vars.map_temp = ft_split(vars.map_buf, '\n');
	map_error(argc, &vars);
	split_cleaner(&vars);
	ft_printf("Success\n");
	return (0);
}
*/
