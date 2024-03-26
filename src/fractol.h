/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:55:07 by caliman           #+#    #+#             */
/*   Updated: 2024/03/25 19:45:33 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define DEC_BASE "0123456789.-"
# define MANDELBROT "Mandelbrot"
# define JULIA "Julia"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATIONS 150

# define PLUS 65451
# define MINUS 65453
# define ESC 65307
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65363
# define ARROW_UP 65362
# define ARROW_LEFT 65361

typedef struct	complex
{
    double  r; //real
    double  i; //imaginário
}		complex;

typedef struct s_params {
    char    *selected_ftl;
    void    *mlx_ptr;
    void    *mlx_win;
    double  zoom;
    int     x_arrow;
    int     y_arrow;
    int     color;
    void    *img;
    char    *addr;
    int     bits;
    int     line_length;
    int     endian;
    double  real_nbr;
    double  imag_nbr;
    
}               t_params;

//utils
char    *ft_strchr(const char *str, int c);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);

//utils2
int		ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
double	ft_atof(const char *str);

//basics
void	start_window(t_params *params, char *win_name);
void	instructions(void);
int		close_window(void *param);

//draw
void	julia_set(t_params *params);
void	mandelbrot_set(t_params *params);

//hooks
int		mouse_zoom(int key, int x, int y, t_params *param);
int		keys_psd(int key, t_params *params);

//img
void	start_image(t_params *params);
void	pixel_put(t_params *img, int x, int y, int iterations);

#endif
