/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:08:32 by gmechaly          #+#    #+#             */
/*   Updated: 2024/11/06 21:08:32 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	draw_julia(t_data *data)
{
	int		i;
	double	temp;

	i = 0;
	convert_coordinates(data);
	while (++i < data->max_iterations)
	{
		temp = data->zx * data->zx - data->zy * data->zy + data->cx;
		data->zy = 2.0 * data->zx * data->zy + data->cy;
		data->zx = temp;
		if (data->zx * data->zx + data->zy * data->zy >= __DBL_MAX__)
			break ;
	}
	if (i == data->max_iterations)
		ft_mlx_pixel_put(data, data->x, data->y, WHITE);
	else
		ft_mlx_pixel_put(data, data->x, data->y, data->color * i * 3);
	return (1);
}

int	draw_mandelbrot(t_data *data)
{
	int		i;
	double	temp;

	i = 0;
	convert_coordinates(data);
	while (++i < data->max_iterations)
	{
		temp = data->zx * data->zx - data->zy * data->zy + data->cx;
		data->zy = 2.0 * data->zx * data->zy + data->cy;
		data->zx = temp;
		if (data->zx * data->zx + data->zy * data->zy >= __DBL_MAX__)
			break ;
	}
	if (i == data->max_iterations)
		ft_mlx_pixel_put(data, data->x, data->y, WHITE);
	else
		ft_mlx_pixel_put(data, data->x, data->y, data->color * i);
	return (1);
}

int	draw_ship(t_data *data)
{
	int		i;
	double	temp;

	i = 0;
	convert_coordinates(data);
	while (++i < data->max_iterations)
	{
		temp = data->zx * data->zx - data->zy * data->zy + data->cx;
		data->zy = ft_fabs(2.0 * data->zx * data->zy) + data->cy;
		data->zx = ft_fabs(temp);
		if (data->zx * data->zx + data->zy * data->zy >= __DBL_MAX__)
			break ;
	}
	if (i == data->max_iterations)
		ft_mlx_pixel_put(data, data->x, data->y, BLACK);
	else
		ft_mlx_pixel_put(data, data->x, data->y, data->color * i);
	return (1);
}

void	draw(t_data *data)
{
	if (ft_strncmp(data->name, "julia", 5) == 0)
		julia(data);
	else if (ft_strncmp(data->name, "mandelbrot", 9) == 0)
		mandelbrot(data);
	else if (ft_strncmp(data->name, "ship", 4) == 0)
		burning_ship(data);
}

void	ft_change_color(t_data *data)
{
	int			color_tab[6];
	static int	i;

	init_color_tab(color_tab);
	if (i == 6)
		i = 0;
	data->color = color_tab[i];
	i++;
	mlx_put_image_to_window((*data).mlx, (*data).window, (*data).image, 0, 0);
}
