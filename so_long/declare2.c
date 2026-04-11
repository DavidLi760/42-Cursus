/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:25:19 by davli             #+#    #+#             */
/*   Updated: 2024/07/04 17:33:48 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg(t_vars *vars, int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		exit(-1);
	vars->map_fd = open(argv[1], O_RDONLY);
	if (vars->map_fd < 0)
		exit (-1);
	vars->map_buf = get_next_line(vars->map_fd);
	if (!vars->map_buf)
		exit ((free(vars->map_buf), 1));
	vars->map_line = ft_split(vars->map_buf, '\n');
	if (!vars->map_line)
		exit ((free(vars->map_buf), 1));
	vars->map_temp = ft_split(vars->map_buf, '\n');
	if (!vars->map_temp)
	{
		vars->map_temp = NULL;
		vars->map_line = NULL;
		split_cleaner(vars);
	}
	map_error(vars);
}

void	vars_declare6(t_vars *vars, int *m)
{
	vars->p1.d5 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish1mort5.xpm", m, m);
	if (!vars->p1.d5)
		close_win(vars);
	vars->p1.d6 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish1mort6.xpm", m, m);
	if (!vars->p1.d6)
		close_win(vars);
	vars->p1.d7 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish1mort7.xpm", m, m);
	if (!vars->p1.d7)
		close_win(vars);
	vars->p2.d1 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2mort1.xpm", m, m);
	if (!vars->p2.d1)
		close_win(vars);
	vars->p2.d2 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2mort2.xpm", m, m);
	if (!vars->p2.d2)
		close_win(vars);
	vars->p2.d3 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2mort3.xpm", m, m);
	if (!vars->p2.d3)
		close_win(vars);
	vars->p2.d4 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2mort4.xpm", m, m);
	if (!vars->p2.d4)
		close_win(vars);
	vars->p2.d5 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2mort5.xpm", m, m);
	if (!vars->p2.d5)
		close_win(vars);
}

void	vars_declare7(t_vars *vars, int *m)
{
	vars->p2.d6 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2mort6.xpm", m, m);
	if (!vars->p2.d6)
		close_win(vars);
	vars->p2.d7 = mlx_xpm_file_to_image(vars->mlx, "xpm/Fish2mort7.xpm", m, m);
	if (!vars->p2.d7)
		close_win(vars);
}

void	init_map_util(t_vars *vars, int i, int j)
{
	int	i2;
	int	j2;

	i2 = i * 65;
	j2 = j * 65;
	if (vars->map_line[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, j2, i2);
	if (vars->map_line[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img0, j2, i2);
	if (vars->map_line[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgc, j2, i2);
	if (vars->map_line[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgp, j2, i2);
	if (vars->map_line[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imge, j2, i2);
}

void	collect_fish2(t_vars *vars)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = vars->p1.x;
	y1 = vars->p1.y;
	x2 = vars->p2.x;
	y2 = vars->p2.y;
	if (vars->map_line[y1 / 65][x1 / 65 + 1] == 'C')
	{
		vars->goal--;
		vars->map_line[y1 / 65][x1 / 65 + 1] = '0';
		init_map2(vars);
	}
	if (vars->map_line[y2 / 65][x2 / 65 + 1] == 'C')
	{
		vars->goal--;
		vars->map_line[y2 / 65][x2 / 65 + 1] = '0';
		init_map2(vars);
	}
}
