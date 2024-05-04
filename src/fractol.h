/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:55:07 by caliman           #+#    #+#             */
/*   Updated: 2024/04/24 17:13:15 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"

# define MANDELBROT "Mandelbrot"
# define JULIA "Julia"
# define DEC_BASE "0123456789.-"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATIONS 50

# define SHIFT 65505
# define ESC 65307
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65363
# define ARROW_UP 65362
# define ARROW_LEFT 65361

typedef struct complex
{
	double	r;
	double	i;
}		t_complex;

typedef struct s_point
{
	int		x;
	int		y;
	int		iterations;
}		t_point;

typedef struct s_params
{
	char	*selected_ftl;
	void	*mlx_ptr;
	void	*mlx_win;
	double	zoom;
	int		x_arrow;
	int		y_arrow;
	int		color;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	double	real_nbr;
	double	imag_nbr;
}		t_params;

//basic0
void	instructions(void);
int		close_window(t_params *params);
void	start_window(t_params *params, char *win_name);
void	cleanup(t_params *params);

//basic1
char	*ft_strchr(const char *str, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);

//basic2
double	ft_atof(const char *str);

//image
void	start_image(t_params *params);

//julia_mandelbrot
void	julia_set(t_params *params);
void	mandelbrot_set(t_params *params);
void	pixel_color(t_params *img, int x, int y, int iterations);

//keyboard
int		keys_psd(int key, t_params *params);

//mouse
int		mouse_zoom(int key, int x, int y, t_params *param);

#endif
