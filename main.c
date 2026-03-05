/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:56:47 by gmechaly          #+#    #+#             */
/*   Updated: 2024/11/29 20:28:13 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

// int	next_frame(t_data *data)
// {
// 	static int	i;

// 	// sleep(1);
// 	// mlx_destroy_image((*data).mlx, (*data).ptr_image);
// 	// if (++i > 10)
// 	// 	return (0);
// 	// if (data->x < 380 && data->y == 20)
// 	// 	data->x += 20;
// 	// else if (data->x == 380 && data->y < 380)
// 	// 	data->y += 20;
// 	// else if (data->x > 20 && data->y == 380)
// 	// 	data->x -= 20;
// 	// else if (data->x == 20 && data->y > 380)
// 	// 	data->y -= 20;
// 	draw(data);
// 	mlx_put_image_to_window((*data).mlx, (*data).window, (*data).image, 0, 0);
// 	return (1);
// }

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2 || (ft_strncmp("julia", argv[1], 5) \
		&& ft_strncmp("mandelbrot", argv[1], 9) \
		&& ft_strncmp("ship", argv[1], 4)))
	{
		ft_putendl_fd("usage : ./fractol <fractal>", 1);
		ft_putendl_fd("available fractales : julia, mandelbrot, ship", 1);
		return (0);
	}
	data = malloc(sizeof(t_data));
	if (init_mlx(data) == NULL)
		return (0);
	init_data(data, argc, argv);
	mlx_key_hook(data->window, handle_key, data);
	mlx_mouse_hook(data->window, handle_mouse, data);
	mlx_hook(data->window, 17, 0L, quit_program, data);
	draw(data);
	mlx_loop(data->mlx);
	quit_program(data);
	return (0);
}
