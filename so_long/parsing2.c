/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:24:11 by davli             #+#    #+#             */
/*   Updated: 2024/07/02 19:30:39 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char **tab, int x, int y)
{
	if (tab[x][y] == '1' || tab[x][y] == 'V')
		return ;
	tab[x][y] = 'V';
	fill(tab, (x - 1), y);
	fill(tab, (x + 1), y);
	fill(tab, x, (y - 1));
	fill(tab, x, (y + 1));
}

int	flood_fill(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	fill(vars->map_temp, vars->p_pos.x, vars->p_pos.y);
	vars->c_count = 0;
	while (vars->map_temp[i])
	{
		j = 0;
		while (vars->map_temp[i][j])
		{
			if (vars->map_temp[i][j] == 'C')
			{
				vars->c_count++;
			}
			j++;
		}
		i++;
	}
	if (vars->map_temp[vars->e_pos.x][vars->e_pos.y] == 'V' && !vars->c_count)
		return (1);
	exit_error(-6, vars);
	return (0);
}

static void	char_counter(char c, t_vars *vars)
{
	if (c == 'E')
		vars->e_count++;
	if (c == 'C')
		vars->c_count++;
	if (c == 'P')
		vars->p_count++;
}

int	check_correct_char(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	if (!vars)
		return (0);
	while (vars->map_line && vars->map_line[i])
	{
		j = 0;
		while (vars->map_line[i] && vars->map_line[i][j])
		{
			char_counter(vars->map_line[i][j], vars);
			if (vars->map_line[i][j] != 'P' && vars->map_line[i][j] != 'E' &&
					vars->map_line[i][j] != 'C' &&
					vars->map_line[i][j] != '1' &&
					vars->map_line[i][j] != '0')
				exit_error(-5, vars);
			j++;
		}
		i++;
	}
	if (vars->e_count != 1 || vars->p_count != 1 || vars->c_count < 1)
		return (0);
	vars->c_left = vars->c_count;
	return (1);
}
