# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caliman <caliman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 21:33:30 by caliman           #+#    #+#              #
#    Updated: 2024/03/26 12:36:33 by caliman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra -g 
MLXFLAGS = -L ./mlx -lbsd -lmlx -lXext -lX11

SRC = basic0.c basic1.c basic2.c mouse.c julia_mandelbrot.c image.c keyboard.c main.c
OBJ_SRC = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) $(MLXFLAGS) -lm -o $(NAME)
	echo "\033[1m Ready to FRACT-OL \033[0m"

clean:
	rm -rf $(SRC:.c=.o)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus

.SILENT: