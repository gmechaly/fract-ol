/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:57:19 by gmechaly          #+#    #+#             */
/*   Updated: 2024/11/29 18:00:13 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// COLORS
# define RED 0x00050101
# define BLUE 0x00010105
# define GREEN 0x00010501
# define CYAN 0x00010505
# define YELLOW 0x00050501
# define PURPLE 0x00050105
# define WHITE 0x00080808
# define BLACK 0x00000000

// USEFUL
# define SIZE 700
# define MIN_JU -2.0
# define MAX_JU 2.0
# define MIN_MA -1.5
# define MAX_MA 3.0

// MOUSE CODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// KEY CODES
# define KEY_W 119
# define KEY_A 97
# define KEY_PLUS 0x00ffab
# define KEY_MINUS 0x00ffad

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <limits.h>
# include "../mlx/mlx.h"
# include "../mylibft/includes/libft.h"

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*ptr_image;
	int		max_iterations;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		color;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	bool	redraw;
}			t_data;

// draw.c
int		draw_mandelbrot(t_data *data);
int		draw_julia(t_data *data);
int		draw_ship(t_data *data);
void	draw(t_data *data);
void	ft_change_color(t_data *data);

// fractals.c
void	julia(t_data *data);
void	mandelbrot(t_data *data);
void	burning_ship(t_data *data);

// frees.c
int		quit_program(t_data *data);

// inits.c
void	*init_mlx(t_data *data);
void	init_color_tab(int	*color_tab);
void	init_data(t_data *data, int argc, char **argv);

// input.c
int		handle_key(int keysim, t_data *data);
void	zoom(t_data *data, int x, int y, int input);
int		handle_mouse(int mouse_code, int x, int y, t_data *data);

// main.c
int		main(int argc, char **argv);

// utils.c
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	convert_coordinates(t_data *data);
double	ft_atof(const char *ptr);
double	power_of_ten(double nb, int power);
double	ft_fabs(double x);

#endif