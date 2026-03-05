/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:17:56 by gmechaly          #+#    #+#             */
/*   Updated: 2024/11/30 14:55:02 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

/*
*	W = UP
*	A = LEFT
*	S = DOWN
*	D = RIGHT
*	+ = INCREASE RESOLUTION
*	- = DECREASE RESOLTUION
*	C = CHANGE COLOR
*/

int	handle_key(int keysim, t_data *data)
{
	if (keysim == KEY_W || keysim == XK_Up)
		data->offset_y -= 42 / data->zoom;
	if (keysim == KEY_A || keysim == XK_Left)
		data->offset_x -= 42 / data->zoom;
	if (keysim == XK_s || keysim == XK_Down)
		data->offset_y += 42 / data->zoom;
	if (keysim == XK_d || keysim == XK_Right)
		data->offset_x += 42 / data->zoom;
	if (keysim == KEY_PLUS && data->max_iterations < INT_MAX)
		data->max_iterations += 8;
	if (keysim == KEY_MINUS && data->max_iterations > 8)
		data->max_iterations -= 8;
	if (keysim == XK_c)
		ft_change_color(data);
	if (keysim == XK_z)
		data->cx += 0.01;
	if (keysim == XK_x)
		data->cy += 0.01;
	if (keysim == XK_Escape)
		quit_program(data);
	draw(data);
	return (0);
}

int	handle_mouse(int mouse_code, int x, int y, t_data *data)
{
	if (mouse_code == SCROLL_UP)
		zoom(data, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(data, x, y, -1);
	draw(data);
	return (1);
}

void	zoom(t_data *data, int x, int y, int input)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (input == 1)
	{
		data->offset_x = (x / data->zoom + data->offset_x) \
						- (x / (data->zoom * zoom_level));
		data->offset_y = (y / data->zoom + data->offset_y) \
						- (y / (data->zoom * zoom_level));
		data->zoom *= zoom_level;
	}
	else if (input == -1)
	{
		data->offset_x = (x / data->zoom + data->offset_x) - (x / \
				(data->zoom / zoom_level));
		data->offset_y = (y / data->zoom + data->offset_y) - (y / \
				(data->zoom / zoom_level));
		data->zoom /= zoom_level;
	}
}
