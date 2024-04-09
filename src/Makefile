# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caliman <caliman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 21:33:30 by caliman           #+#    #+#              #
#    Updated: 2024/04/04 22:37:52 by caliman          ###   ########.fr        #
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

clean:
	rm -rf $(OBJ_SRC)

fclean: clean
	rm -rf $(NAME)

re: fclean all
