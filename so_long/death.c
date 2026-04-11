/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:27:38 by davli             #+#    #+#             */
/*   Updated: 2024/07/04 16:58:29 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	death_animation2(t_vars *vars, t_player *p2)
{
	if (p2->dead == 0)
		vars->death_j = 0;
	if (vars->death_j <= 50 && vars->death_j)
		mlx_put_image_to_window(vars->mlx, vars->win, p2->d1, p2->x, p2->y);
	if (vars->death_j <= 100 && vars->death_j > 50)
		mlx_put_image_to_window(vars->mlx, vars->win, p2->d2, p2->x, p2->y);
	if (vars->death_j <= 150 && vars->death_j > 100)
		mlx_put_image_to_window(vars->mlx, vars->win, p2->d3, p2->x, p2->y);
	if (vars->death_j <= 200 && vars->death_j > 150)
		mlx_put_image_to_window(vars->mlx, vars->win, p2->d4, p2->x, p2->y);
	if (vars->death_j <= 250 && vars->death_j > 200)
		mlx_put_image_to_window(vars->mlx, vars->win, p2->d5, p2->x, p2->y);
	if (vars->death_j <= 300 && vars->death_j > 250)
		mlx_put_image_to_window(vars->mlx, vars->win, p2->d6, p2->x, p2->y);
	if (vars->death_j <= 350 && vars->death_j > 300)
		mlx_put_image_to_window(vars->mlx, vars->win, p2->d7, p2->x, p2->y);
	if (vars->death_j >= 351)
		vars->death2 = 1;
}

void	death_animation1(t_vars *vars, t_player *p1)
{
	if (p1->dead == 0)
		vars->death_i = 0;
	if (vars->death_i <= 50 && vars->death_i)
		mlx_put_image_to_window(vars->mlx, vars->win, p1->d1, p1->x, p1->y);
	if (vars->death_i <= 100 && vars->death_i > 50)
		mlx_put_image_to_window(vars->mlx, vars->win, p1->d2, p1->x, p1->y);
	if (vars->death_i <= 150 && vars->death_i > 100)
		mlx_put_image_to_window(vars->mlx, vars->win, p1->d3, p1->x, p1->y);
	if (vars->death_i <= 200 && vars->death_i > 150)
		mlx_put_image_to_window(vars->mlx, vars->win, p1->d4, p1->x, p1->y);
	if (vars->death_i <= 250 && vars->death_i > 200)
		mlx_put_image_to_window(vars->mlx, vars->win, p1->d5, p1->x, p1->y);
	if (vars->death_i <= 300 && vars->death_i > 250)
		mlx_put_image_to_window(vars->mlx, vars->win, p1->d6, p1->x, p1->y);
	if (vars->death_i <= 350 && vars->death_i > 300)
		mlx_put_image_to_window(vars->mlx, vars->win, p1->d7, p1->x, p1->y);
	if (vars->death_i >= 351)
		vars->death1 = 1;
}

void	kill_player(t_vars *vars)
{
	if (vars->p1.x >= vars->p3.x - 65
		&& vars->p1.x <= vars->p3.x + 65
		&& vars->p1.y >= vars->p3.y - 65 && vars->p3.y
		&& vars->p1.y <= vars->p3.y + 65)
		if (vars->i <= 0 && !vars->p1.dead && vars->goal)
			vars->p1.dead = 1;
	if (vars->p2.x >= vars->p3.x - 65
		&& vars->p2.x <= vars->p3.x + 65
		&& vars->p2.y >= vars->p3.y - 65 && vars->p3.y
		&& vars->p2.y <= vars->p3.y + 65)
		if (vars->i <= 0 && !vars->p2.dead && vars->goal)
			vars->p2.dead = 1;
	if (vars->p1.dead && vars->p2.dead
		&& vars->death1 == 1 && vars->death2 == 1)
	{
		ft_printf("**************\n");
		ft_printf("* Game Over! *\n* You lose ! *\n");
		ft_printf("**************\n");
		close_win(vars);
	}
}

void	player_death(t_vars *vars)
{
	kill_player(vars);
	if (!vars->death1)
		death_animation1(vars, &vars->p1);
	if (!vars->death2)
		death_animation2(vars, &vars->p2);
}
