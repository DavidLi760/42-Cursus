/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:51:29 by davli             #+#    #+#             */
/*   Updated: 2024/07/03 18:24:35 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_win_util1(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img0)
		mlx_destroy_image(vars->mlx, vars->img0);
	if (vars->img1)
		mlx_destroy_image(vars->mlx, vars->img1);
	if (vars->imgc)
		mlx_destroy_image(vars->mlx, vars->imgc);
	if (vars->imgp)
		mlx_destroy_image(vars->mlx, vars->imgp);
	if (vars->imge)
		mlx_destroy_image(vars->mlx, vars->imge);
	if (vars->imge2)
		mlx_destroy_image(vars->mlx, vars->imge2);
	if (vars->p1.img_d)
		mlx_destroy_image(vars->mlx, vars->p1.img_d);
	if (vars->p1.img_g)
		mlx_destroy_image(vars->mlx, vars->p1.img_g);
	if (vars->p2.img_d)
		mlx_destroy_image(vars->mlx, vars->p2.img_d);
	if (vars->p2.img_g)
		mlx_destroy_image(vars->mlx, vars->p2.img_g);
	if (vars->p3.img_d)
		mlx_destroy_image(vars->mlx, vars->p3.img_d);
	if (vars->p3.img_g)
		mlx_destroy_image(vars->mlx, vars->p3.img_g);
}

void	close_win_util2(t_vars *vars)
{
	if (vars->p1.d1)
		mlx_destroy_image(vars->mlx, vars->p1.d1);
	if (vars->p1.d2)
		mlx_destroy_image(vars->mlx, vars->p1.d2);
	if (vars->p1.d3)
		mlx_destroy_image(vars->mlx, vars->p1.d3);
	if (vars->p1.d4)
		mlx_destroy_image(vars->mlx, vars->p1.d4);
	if (vars->p1.d5)
		mlx_destroy_image(vars->mlx, vars->p1.d5);
	if (vars->p1.d6)
		mlx_destroy_image(vars->mlx, vars->p1.d6);
	if (vars->p1.d7)
		mlx_destroy_image(vars->mlx, vars->p1.d7);
	if (vars->p2.d1)
		mlx_destroy_image(vars->mlx, vars->p2.d1);
	if (vars->p2.d2)
		mlx_destroy_image(vars->mlx, vars->p2.d2);
	if (vars->p2.d3)
		mlx_destroy_image(vars->mlx, vars->p2.d3);
	if (vars->p2.d4)
		mlx_destroy_image(vars->mlx, vars->p2.d4);
	if (vars->p2.d5)
		mlx_destroy_image(vars->mlx, vars->p2.d5);
}

int	close_win(t_vars *vars)
{
	int	i;

	i = 0;
	close_win_util1(vars);
	close_win_util2(vars);
	if (vars->p2.d6)
		mlx_destroy_image(vars->mlx, vars->p2.d6);
	if (vars->p2.d7)
		mlx_destroy_image(vars->mlx, vars->p2.d7);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	if (vars->mlx)
		free(vars->mlx);
	if (vars->key_state)
		free(vars->key_state);
	if (vars->map_pixel)
	{
		while (i < 976 && vars->map_pixel[i])
			free(vars->map_pixel[i++]);
		free(vars->map_pixel);
	}
	split_cleaner(vars);
	exit (0);
	return (0);
}

void	split_cleaner(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map_line)
		while (vars->map_line[i])
			free(vars->map_line[i++]);
	i = 0;
	if (vars->map_temp)
		while (vars->map_temp[i])
			free(vars->map_temp[i++]);
	free(vars->map_line);
	free(vars->map_temp);
	free(vars->map_buf);
	close(vars->map_fd);
	exit (0);
}

void	exit_error(int error, t_vars *vars)
{
	if (error == -9)
		ft_printf("Error : Map incorrect size");
	if (error == -8)
		ft_printf("Error : Map wall not closed");
	if (error == -7)
		ft_printf("Error : Need 1 exit, 1 player spawn and 1+ collectible");
	if (error == -6)
		ft_printf("Error : Map doesn't have valid path");
	if (error == -5)
		ft_printf("Error : Map has unknown characters");
	split_cleaner(vars);
	exit (1);
}
