/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:45:00 by davli             #+#    #+#             */
/*   Updated: 2024/08/24 16:14:36 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	portal_open(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->e_pos.x * 65;
	y = vars->e_pos.y * 65;
	if (vars->goal == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imge2, y, x);
}

void	winning(t_vars *vars)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = vars->p1.x / 65;
	y1 = vars->p1.y / 65;
	x2 = vars->p2.x / 65;
	y2 = vars->p2.y / 65;
	if (!vars->goal)
	{
		if (vars->map_line[y1][x1] == 'E' && !vars->p1.dead)
		{
			ft_printf("********************\n* Congratulation ! *\n");
			ft_printf("*    You win       *\n********************\n");
			close_win(vars);
		}
		if (vars->map_line[y2][x2] == 'E' && !vars->p2.dead)
		{
			ft_printf("********************\n* Congratulation ! *\n");
			ft_printf("*    You win       *\n********************\n");
			close_win(vars);
		}
	}
}

void	collect_fish(t_vars *vars)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = vars->p1.x;
	y1 = vars->p1.y;
	x2 = vars->p2.x;
	y2 = vars->p2.y;
	if (vars->map_line[y1 / 65][x1 / 65] == 'C')
	{
		vars->goal--;
		vars->map_line[y1 / 65][x1 / 65] = '0';
		init_map2(vars);
	}
	if (vars->map_line[y2 / 65][x2 / 65] == 'C')
	{
		vars->goal--;
		vars->map_line[y2 / 65][x2 / 65] = '0';
		init_map2(vars);
	}
	collect_fish2(vars);
}

void	counter(t_vars *vars)
{
	char	*move;
	char	*left;
	int		b;

	b = 0x00FFFFFF;
	left = ft_itoa(vars->goal);
	if (!left)
		close_win(vars);
	move = ft_itoa(vars->mv_count);
	if (!move)
	{
		free(left);
		close_win(vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, 65, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, 195, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img1, 260, 0);
	mlx_string_put(vars->mlx, vars->win, 15, 40, b, move);
	mlx_string_put(vars->mlx, vars->win, 15, 20, b, "Movement count :");
	mlx_string_put(vars->mlx, vars->win, 215, 40, b, left);
	mlx_string_put(vars->mlx, vars->win, 215, 20, b, "Collectible left :");
	free(move);
	free(left);
}

void	win_condition(t_vars *vars)
{
	counter(vars);
	collect_fish(vars);
	winning(vars);
	portal_open(vars);
}
