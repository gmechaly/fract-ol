/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:59:11 by gmechaly          #+#    #+#             */
/*   Updated: 2024/11/30 14:56:23 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	julia(t_data *data)
{
	if (data->cx == 0 && data->cy == 0)
	{
		data->cx = -0.745429;
		data->cy = 0.05;
	}
	data->y = 0;
	while (data->y < SIZE)
	{
		data->x = 0;
		while (data->x < SIZE)
		{
			draw_julia(data);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window((*data).mlx, (*data).window, (*data).image, 0, 0);
}

void	mandelbrot(t_data *data)
{
	data->x = 0;
	while (data->x < SIZE)
	{
		data->y = 0;
		while (data->y < SIZE)
		{
			draw_mandelbrot(data);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window((*data).mlx, (*data).window, (*data).image, 0, 0);
}

void	burning_ship(t_data *data)
{
	data->x = 0;
	while (data->x < SIZE)
	{
		data->y = 0;
		while (data->y < SIZE)
		{
			draw_ship(data);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window((*data).mlx, (*data).window, (*data).image, 0, 0);
}
