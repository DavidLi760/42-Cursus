/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:48:09 by davli             #+#    #+#             */
/*   Updated: 2024/07/03 20:03:31 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	press_w(t_vars *vars, t_player *p1)
{
	int	x;
	int	y;

	x = p1->x;
	y = p1->y;
	if (vars->key_state[W] && vars->map_pixel[p1->y - 1][p1->x] != 1)
	{
		if (!p1->dead)
		{
			vars->mv_count += 1;
			p1->y -= 1;
			if (vars->key_state[D])
				mlx_put_image_to_window(vars->mlx, vars->win, p1->img_d, x, y);
			else if (vars->key_state[A])
				mlx_put_image_to_window(vars->mlx, vars->win, p1->img_g, x, y);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, p1->img_d, x, y);
		}
	}
}

void	press_s(t_vars *vars, t_player *p1)
{
	int	x;
	int	y;

	x = p1->x;
	y = p1->y;
	if (vars->key_state[S] && vars->map_pixel[y + 1][x] != 1)
	{
		if (!p1->dead)
		{
			vars->mv_count += 1;
			p1->y += 1;
			if (vars->key_state[D])
				mlx_put_image_to_window(vars->mlx, vars->win, p1->img_d, x, y);
			else if (vars->key_state[A])
				mlx_put_image_to_window(vars->mlx, vars->win, p1->img_g, x, y);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, p1->img_d, x, y);
		}
	}
}

void	press_d_a(t_vars *vars, t_player *p1)
{
	int	x;
	int	y;

	x = p1->x;
	y = p1->y;
	if (vars->key_state[A] && vars->map_pixel[y][x - 1] != 1)
	{
		if (!p1->dead)
		{
			vars->mv_count += 1;
			p1->x -= 1;
			mlx_put_image_to_window(vars->mlx, vars->win, p1->img_g, x, y);
		}
	}
	if (vars->key_state[D] && vars->map_pixel[y][x + 1] != 1)
	{
		if (!p1->dead)
		{
			vars->mv_count += 1;
			p1->x += 1;
			mlx_put_image_to_window(vars->mlx, vars->win, p1->img_d, x, y);
		}
	}
}

void	press_button(t_vars *vars)
{
	press_w(vars, &vars->p1);
	press_s(vars, &vars->p1);
	press_d_a(vars, &vars->p1);
}
