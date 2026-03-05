# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 18:58:22 by gmechaly          #+#    #+#              #
#    Updated: 2024/11/29 17:59:10 by gmechaly         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -I$(INCLUDES)
NAME = fractol
INCLUDES = includes/ #/usr/include mlx_linux -O3
FILES = frees.c fractals.c utils.c input.c inits.c main.c draw.c
OBJ = $(FILES:.c=.o)

LIBFT_DIR = mylibft/
LIBFT = mylibft/libft.a
LIBFT_H = mylibft/includes/

MLX = mlx
MLXFLAGS = -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJ) -L$(MLX) -I$(MLX) $(MLXFLAGS) $(LIBFT) -o $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES) -I$(LIBFT_H) -I$(MLX)

$(LIBFT) :
	make -C $(LIBFT_DIR)
	make -C $(MLX)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX)

re: fclean all

.PHONY: clean fclean re all