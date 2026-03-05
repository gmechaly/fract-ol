/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:10:02 by gmechaly          #+#    #+#             */
/*   Updated: 2024/11/13 18:17:33 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > SIZE || y > SIZE)
	{
		perror("Error : out of window.");
		return ;
	}
	dst = data->ptr_image + \
	(y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	convert_coordinates(t_data *data)
{
	if (ft_strncmp("julia", (*data).name, 5) == 0)
	{	
		data->zx = data->x / data->zoom + data->offset_x;
		data->zy = data->y / data->zoom + data->offset_y;
	}
	else if (ft_strncmp("mandelbrot", (*data).name, 9) == 0 \
			|| ft_strncmp("ship", (*data).name, 4) == 0)
	{
		data->zx = 0.0;
		data->zy = 0.0;
		data->cx = (data->x / data->zoom) + data->offset_x;
		data->cy = (data->y / data->zoom) + data->offset_y;
	}
}

double	ft_atof(const char *ptr)
{
	int		i;
	int		j;
	int		sign;
	double	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((ptr[i] <= '\r' && ptr[i] >= '\t') || ptr[i] == ' ')
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			sign = -1;
		i++;
	}
	while ((ptr[i] >= '0' && ptr[i] <= '9') || ptr[i] == '.')
	{
		if (ptr[i] == '.')
			j = i++;
		result *= 10;
		result += ptr[i] - '0';
		i++;
	}
	return (power_of_ten(sign * result, j - i + 1));
}

double	power_of_ten(double nb, int power)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (power < 0)
		sign = -1;
	while (i < power * sign)
	{
		if (sign == -1)
			nb /= 10;
		else
			nb *= 10;
		i++;
	}
	return (nb);
}

double	ft_fabs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}
