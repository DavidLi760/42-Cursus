/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:26:07 by davli             #+#    #+#             */
/*   Updated: 2024/07/04 18:29:32 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_player(t_vars *vars, t_player *p1, t_player *p2)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = p1->x;
	y1 = p1->y;
	x2 = p2->x;
	y2 = p2->y;
	if (!vars->p1.dead)
		mlx_put_image_to_window(vars->mlx, vars->win, p1->img_d, x1, y1);
	if (vars->key_state[A] && !vars->p1.dead && !vars->key_state[D])
		mlx_put_image_to_window(vars->mlx, vars->win, p1->img_g, x1, y1);
	if (!vars->p2.dead)
		mlx_put_image_to_window(vars->mlx, vars->win, p2->img_d, x2, y2);
	if (vars->key_state[LEFT] && !vars->p2.dead && !vars->key_state[RIGHT])
		mlx_put_image_to_window(vars->mlx, vars->win, p2->img_g, x2, y2);
}

void	init_map2(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map_line[i])
	{
		j = 0;
		while (vars->map_line[i][j])
		{
			init_map_util(vars, i, j);
			j++;
		}
		i++;
	}
	init_map_player(vars, &vars->p1, &vars->p2);
}

void	init_map(t_vars *vars)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = vars->p3.x;
	y = vars->p3.y;
	i = 0;
	while (vars->map_line[i])
	{
		j = 0;
		while (vars->map_line[i][j])
		{
			init_map_util(vars, i, j);
			j++;
		}
		i++;
	}
	init_map_player(vars, &vars->p1, &vars->p2);
	if (vars->i <= -3)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p3.img_d, x, y);
	if (vars->i <= -3 && vars->p3.x > vars->mouse_x - 32 && vars->p3.x > 65)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p3.img_g, x, y);
}

void	forbidden_zone(t_vars *vars, int i, int j)
{
	int	forbidden;
	int	temp_i;
	int	temp_j;

	forbidden = 0;
	if (vars->map_line[i][j] == '1')
		forbidden = 1;
	temp_i = i * 65;
	temp_j = j * 65;
	while (temp_i <= (i + 1) * 65)
	{
		temp_j = j * 65;
		while (temp_j <= (j + 1) * 65)
		{
			if (forbidden == 1 && i > 0 && j > 0)
			{
				vars->map_pixel[temp_i - 64][temp_j - 1] = forbidden;
				vars->map_pixel[temp_i - 1][temp_j - 64] = forbidden;
				vars->map_pixel[temp_i - 64][temp_j - 64] = forbidden;
			}
			vars->map_pixel[temp_i][temp_j] = forbidden;
			temp_j++;
		}
		temp_i++;
	}
}

void	init_zone(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map_line[i])
	{
		j = 0;
		while (vars->map_line[i][j])
		{
			forbidden_zone(vars, i, j);
			j++;
		}
		i++;
	}
	vars->p1.x = vars->p_pos.y * 65;
	vars->p1.y = vars->p_pos.x * 65;
	vars->p2.x = vars->p_pos.y * 65;
	vars->p2.y = vars->p_pos.x * 65;
	vars->p3.x = vars->e_pos.y * 65;
	vars->p3.y = vars->e_pos.x * 65;
	vars->update_counter = 101;
}
