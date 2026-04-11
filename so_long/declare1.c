/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:49:33 by davli             #+#    #+#             */
/*   Updated: 2024/07/04 18:21:01 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vars_declare1(t_vars *vars, int argc, char **argv)
{
	vars->i = 2000;
	vars->p1.dead = 0;
	vars->p2.dead = 0;
	vars->death_i = 0;
	vars->death_j = 0;
	vars->death1 = 0;
	vars->death2 = 0;
	vars->boost_i = 0;
	vars->c_count = 0;
	vars->e_count = 0;
	vars->p_count = 0;
	check_arg(vars, argc, argv);
	vars->mv_count = 0;
	vars->mouse_pressed = 0;
	vars->goal = vars->c_left;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->key_state = NULL;
	vars->map_pixel = NULL;
	vars->img0 = NULL;
	vars->img1 = NULL;
	vars->imgp = NULL;
	vars->imge = NULL;
	vars->imge2 = NULL;
	vars->imgc = NULL;
}

void	vars_declare2(t_vars *vars)
{
	vars->p1.img_d = NULL;
	vars->p1.img_g = NULL;
	vars->p2.img_d = NULL;
	vars->p2.img_g = NULL;
	vars->p3.img_d = NULL;
	vars->p3.img_g = NULL;
	vars->p1.d1 = NULL;
	vars->p1.d2 = NULL;
	vars->p1.d3 = NULL;
	vars->p1.d4 = NULL;
	vars->p1.d5 = NULL;
	vars->p1.d6 = NULL;
	vars->p1.d7 = NULL;
	vars->p2.d1 = NULL;
	vars->p2.d2 = NULL;
	vars->p2.d3 = NULL;
	vars->p2.d4 = NULL;
	vars->p2.d5 = NULL;
	vars->p2.d6 = NULL;
	vars->p2.d7 = NULL;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit (-1);
}

void	vars_declare3(t_vars *vars, int x, int y)
{
	int	i;

	vars->win = mlx_new_window(vars->mlx, x * 65, y * 65, "so_long");
	if (!vars->mlx)
	{
		free(vars->mlx);
		exit (-1);
	}
	i = -1;
	vars->key_state = malloc(sizeof(int) * 65365);
	if (!vars->key_state)
		close_win(vars);
	vars->map_pixel = malloc(sizeof(int *) * 976);
	if (!vars->map_pixel)
		close_win(vars);
	while (++i < 976)
	{
		vars->map_pixel[i] = malloc(sizeof(int) * 1886);
		if (!vars->map_pixel[i])
			close_win(vars);
	}
	i = 0;
	while (i < 65365)
		vars->key_state[i++] = 0;
}

void	vars_declare4(t_vars *vars, int *m)
{
	vars->img0 = mlx_xpm_file_to_image(vars->mlx, "xpm/Eau.xpm", m, m);
	if (!vars->img0)
		close_win(vars);
	vars->imgp = mlx_xpm_file_to_image(vars->mlx, "xpm/Spawn.xpm", m, m);
	if (!vars->imgp)
		close_win(vars);
	vars->img1 = mlx_xpm_file_to_image(vars->mlx, "xpm/Wall.xpm", m, m);
	if (!vars->img1)
		close_win(vars);
	vars->imgc = mlx_xpm_file_to_image(vars->mlx, "xpm/Collectible.xpm", m, m);
	if (!vars->imgc)
		close_win(vars);
	vars->imge = mlx_xpm_file_to_image(vars->mlx, "xpm/PortalClose.xpm", m, m);
	if (!vars->imge)
		close_win(vars);
	vars->imge2 = mlx_xpm_file_to_image(vars->mlx, "xpm/PortalOpen.xpm", m, m);
	if (!vars->imge2)
		close_win(vars);
	vars->p1.img_d = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish1d.xpm", m, m);
	if (!vars->p1.img_d)
		close_win(vars);
	vars->p1.img_g = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish1g.xpm", m, m);
	if (!vars->p1.img_g)
		close_win(vars);
}

void	vars_declare5(t_vars *vars, int *m)
{
	vars->p2.img_g = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2g.xpm", m, m);
	if (!vars->p2.img_g)
		close_win(vars);
	vars->p2.img_d = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2d.xpm", m, m);
	if (!vars->p2.img_d)
		close_win(vars);
	vars->p3.img_g = mlx_xpm_file_to_image(vars->mlx, "xpm/Ghost2g.xpm", m, m);
	if (!vars->p3.img_g)
		close_win(vars);
	vars->p3.img_d = mlx_xpm_file_to_image(vars->mlx, "xpm/Ghost2d.xpm", m, m);
	if (!vars->p3.img_d)
		close_win(vars);
	vars->p1.d1 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish1mort1.xpm", m, m);
	if (!vars->p1.d1)
		close_win(vars);
	vars->p1.d2 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish1mort2.xpm", m, m);
	if (!vars->p1.d2)
		close_win(vars);
	vars->p1.d3 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish1mort3.xpm", m, m);
	if (!vars->p1.d3)
		close_win(vars);
	vars->p1.d4 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish1mort4.xpm", m, m);
	if (!vars->p1.d4)
		close_win(vars);
}
