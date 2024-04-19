/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:15:32 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/04/19 19:09:29 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	instructions(void)
{
	ft_putstr_fd("Welcome to the frac-ol program.\n", 1);
	ft_putstr_fd("Now you will begin to discover the world of fractals.\n", 1);
	ft_putstr_fd("First argument, choose a fractal to explore.\n", 1);
	ft_putstr_fd("Options: ¨Mandelbrot¨ or ¨Julia [real] [imaginary]¨\n", 1);
	ft_putstr_fd("If you choose Julia, you have to input:\n", 1);
	ft_putstr_fd("A real number, and a imaginary number, respectively.\n", 1);
	ft_putstr_fd("They can be doubles.\n", 1);
	ft_putstr_fd("Let's go!\n", 1);
}

int	close_window(void *param)
{
	t_params	*params;

	params = (t_params *)param;
	mlx_destroy_window(params->mlx_ptr, params->mlx_win);
	mlx_destroy_display(params->mlx_ptr);
	mlx_destroy_image(params->mlx_ptr, params->img);
	(void)param;
	exit(0);
}

void	start_window(t_params *params, char *selected_ftl)
{
	params->mlx_ptr = mlx_init();
	if (!params->mlx_ptr)
	{
		ft_putstr_fd("Error -> mlx_init()", 2);
		cleanup(params);
		exit(0);
	}
	params->mlx_win = mlx_new_window(params->mlx_ptr, WIDTH, HEIGHT,
			selected_ftl);
	if (!params->mlx_win)
	{
		ft_putstr_fd("Error -> mlx_new_window()", 2);
		cleanup(params);
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
