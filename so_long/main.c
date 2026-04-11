/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:08:40 by davli             #+#    #+#             */
/*   Updated: 2024/08/24 16:20:05 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spawn_boost(t_vars *vars, int x, int y)
{
	vars->i--;
	if (vars->boost_i >= 4242)
	{
		if (vars->boost_i == 4242)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->imgp, y, x);
		if (vars->p1.x == vars->y && vars->p1.y == vars->x)
		{
			if (!vars->p1.dead)
			{
				vars->boost_i = 0;
				init_map(vars);
			}
		}
		if (vars->p2.x == vars->y && vars->p2.y == vars->x)
		{
			if (!vars->p2.dead)
			{
				vars->boost_i = 0;
				init_map(vars);
			}
		}
	}
}

void	mouse_press1(t_vars *vars, t_player *p3)
{
	int	x;
	int	y;

	x = p3->x;
	y = p3->y;
	init_map(vars);
	if (p3->x > vars->mouse_x - 32 && p3->x > 65)
	{
		p3->x -= 1;
		mlx_put_image_to_window(vars->mlx, vars->win, p3->img_g, x, y);
	}
	if (p3->x < vars->mouse_x - 32 && p3->x < 1755)
	{	
		p3->x += 1;
		mlx_put_image_to_window(vars->mlx, vars->win, p3->img_d, x, y);
	}
}

void	mouse_press2(t_vars *vars, t_player *p3)
{
	int	x;
	int	y;

	x = p3->x;
	y = p3->y;
	if (p3->y > vars->mouse_y - 32 && p3->y > 65)
	{	
		p3->y -= 1;
		if (p3->x > vars->mouse_x - 32)
			mlx_put_image_to_window(vars->mlx, vars->win, p3->img_g, x, y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, p3->img_d, x, y);
	}
	if (p3->y < vars->mouse_y - 32 && p3->y < 845)
	{
		p3->y += 1;
		if (p3->x > vars->mouse_x - 32)
			mlx_put_image_to_window(vars->mlx, vars->win, p3->img_g, x, y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, p3->img_d, x, y);
	}
	vars->i = 0;
}

int	update(t_vars *vars)
{
	vars->update_counter++;
	if (vars->update_counter >= 400)
	{
		press_button(vars);
		press_arrow(vars);
		if (vars->mouse_pressed == 1)
		{
			if (vars->i <= -3)
			{
				mouse_press1(vars, &vars->p3);
				mouse_press2(vars, &vars->p3);
			}
		}
		player_death(vars);
		win_condition(vars);
		spawn_boost(vars, vars->x, vars->y);
		vars->death_i++;
		vars->i--;
		vars->death_j++;
		vars->boost_i++;
		vars->update_counter = 0;
		if (vars->mv_count > 42000)
			vars->goal = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars_declare1(&vars, argc, argv);
	vars_declare2(&vars);
	vars_declare3(&vars, vars.map_width, vars.map_height);
	vars_declare4(&vars, &vars.img);
	vars_declare5(&vars, &vars.img);
	vars_declare6(&vars, &vars.img);
	vars_declare7(&vars, &vars.img);
	init_map2(&vars);
	init_zone(&vars);
	vars.x = vars.p_pos.x * 65;
	vars.y = vars.p_pos.y * 65;
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars);
	mlx_loop_hook(vars.mlx, update, &vars);
	mlx_hook(vars.win, 4, 1L << 2, mouse_press, &vars);
	mlx_hook(vars.win, 5, 1L << 3, mouse_release, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_move, &vars);
	mlx_loop(vars.mlx);
}
