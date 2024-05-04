# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 21:33:30 by caliman           #+#    #+#              #
#    Updated: 2024/04/24 17:24:31 by fgomes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = basic0.c basic1.c basic2.c mouse.c julia_mandelbrot.c image.c keyboard.c main.c

OBJ_SRC = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g 
MLX_PATH = ../minilibx-linux
MLXFLAGS = -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm 

all: $(NAME)

$(NAME): $(OBJ_SRC)
	make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJ_SRC) $(MLXFLAGS) -o $(NAME)
	

clean:
	rm -rf $(OBJ_SRC)

fclean: clean
	rm -rf $(NAME)

re: fclean all
