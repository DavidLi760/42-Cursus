/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:14:59 by davli             #+#    #+#             */
/*   Updated: 2024/07/07 15:18:47 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	press_up(t_vars *vars, t_player *p2)
{
	int	x;
	int	y;

	x = p2->x;
	y = p2->y;
	if (vars->key_state[UP] && vars->map_pixel[y - 1][x] != 1)
	{
		if (!p2->dead)
		{
			vars->mv_count += 1;
			p2->y -= 1;
			if (vars->key_state[RIGHT])
				mlx_put_image_to_window(vars->mlx, vars->win, p2->img_d, x, y);
			else if (vars->key_state[LEFT])
				mlx_put_image_to_window(vars->mlx, vars->win, p2->img_g, x, y);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, p2->img_d, x, y);
		}
	}
}

void	press_down(t_vars *vars, t_player *p2)
{
	int	x;
	int	y;

	x = p2->x;
	y = p2->y;
	if (vars->key_state[DOWN] && vars->map_pixel[y + 1][x] != 1)
	{
		if (!p2->dead)
		{
			vars->mv_count += 1;
			p2->y += 1;
			if (vars->key_state[RIGHT])
				mlx_put_image_to_window(vars->mlx, vars->win, p2->img_d, x, y);
			else if (vars->key_state[LEFT])
				mlx_put_image_to_window(vars->mlx, vars->win, p2->img_g, x, y);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, p2->img_d, x, y);
		}
	}
}

void	press_left_right(t_vars *vars, t_player *p2)
{
	int	x;
	int	y;

	x = p2->x;
	y = p2->y;
	if (vars->key_state[LEFT] && vars->map_pixel[y][x - 1] != 1)
	{
		if (!p2->dead)
		{
			vars->mv_count += 1;
			p2->x -= 1;
			mlx_put_image_to_window(vars->mlx, vars->win, p2->img_g, x, y);
		}
	}
	if (vars->key_state[RIGHT] && vars->map_pixel[y][x + 1] != 1)
	{
		if (!p2->dead)
		{
			vars->mv_count += 1;
			p2->x += 1;
			mlx_put_image_to_window(vars->mlx, vars->win, p2->img_d, x, y);
		}
	}
}

void	press_arrow(t_vars *vars)
{
	press_up(vars, &vars->p2);
	press_down(vars, &vars->p2);
	press_left_right(vars, &vars->p2);
}
