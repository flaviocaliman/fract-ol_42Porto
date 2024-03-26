/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:39:16 by caliman           #+#    #+#             */
/*   Updated: 2024/03/25 14:51:17 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	instructions()
{
	ft_putstr_fd("Welcome to the frac-ol program.\n", 1);
    ft_putstr_fd("Now you will begin to discover the crazy world of fractals.\n", 1);
	ft_putstr_fd("\033[0;37m\e[1mFirst argument\033[0;m\e[m, you need to choose whitch fractal to explore.\n", 1);
	ft_putstr_fd("Options: \033[0;37m\e[1mMandelbrot \033[0;m\e[mor \033[0;37m\e[1mJulia [real] [imaginary]\n", 1);
	ft_putstr_fd("If you choose \033[0;37m\e[1mJulia\033[0;m\e[m, you have to input:\n", 1);
	ft_putstr_fd("A real number, and a imaginary number, respectively.\n", 1);
	ft_putstr_fd("For the calculus of the complex number 'C'. They can be \033[0;37m\e[1mdoubles\033[0;m\e[m.\n", 1);
	ft_putstr_fd("Let's go!\n", 1);
}

int		close_window(void *param)
{
	(void)param;
	exit(0);
}

void    start_window(t_params *params, char *selected_ftl)
{
    params->mlx_ptr = mlx_init();
    if (!params->mlx_ptr)
    {
        ft_putstr_fd("Error -> mlx_init()", 2);
        exit(0);
    }
    params->mlx_win = mlx_new_window(params->mlx_ptr, WIDTH, HEIGHT, selected_ftl);
    if (!params->mlx_win)
    {
        ft_putstr_fd("Error -> mlx_new_window()", 2);
        exit(0);
    }
    params->zoom = 1.0;
    if (!ft_strcmp(selected_ftl, "Julia Set"))
        params->selected_ftl = "Julia";
    if (!ft_strcmp(selected_ftl, "Mandelbrot Set"))
        params->selected_ftl = "Mandelbrot";
    params->x_arrow = 0;
    params->y_arrow = 0;
    params->color = 1;
}
