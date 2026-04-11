/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:43:34 by davli             #+#    #+#             */
/*   Updated: 2024/07/03 19:46:29 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouse_press(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
		vars->mouse_pressed = 1;
	vars->mouse_x = x;
	vars->mouse_y = y;
	return (0);
}

int	mouse_release(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
		vars->mouse_pressed = 0;
	vars->mouse_x = x;
	vars->mouse_y = y;
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	if (vars->mouse_pressed == 1)
	{
		vars->mouse_x = x;
		vars->mouse_y = y;
	}
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_win(vars);
	else if (keycode >= 0 && keycode < 65365)
		vars->key_state[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode >= 0 && keycode < 65365)
		vars->key_state[keycode] = 0;
	return (0);
}
