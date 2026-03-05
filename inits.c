/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:51:37 by gmechaly          #+#    #+#             */
/*   Updated: 2024/11/13 18:40:14 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	*init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (NULL);
	data->image = mlx_new_image(data->mlx, SIZE, SIZE);
	data->ptr_image = mlx_get_data_addr(data->image, &data->bits_per_pixel, \
	&data->size_line, &data->endian);
	data->window = mlx_new_window(data->mlx, SIZE, SIZE, "fract-ol");
	if (!data->window)
		return (quit_program(data), NULL);
	return (data);
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->x = 0;
	data->y = 0;
	data->cx = 0;
	data->cy = 0;
	data->color = 0x050501;
	data->zoom = 300;
	data->offset_x = -1.21;
	data->offset_y = -1.21;
	data->name = argv[1];
	data->max_iterations = 202;
	if (!ft_strncmp(data->name, "ship", 4))
		data->max_iterations = 40;
	if (!ft_strncmp(data->name, "julia", 5) && argc == 4)
	{
		data->cx = ft_atof(argv[2]);
		data->cy = ft_atof(argv[3]);
	}
}

void	init_color_tab(int	*color_tab)
{
	color_tab[0] = RED;
	color_tab[1] = BLUE;
	color_tab[2] = GREEN;
	color_tab[3] = CYAN;
	color_tab[4] = YELLOW;
	color_tab[5] = PURPLE;
}
