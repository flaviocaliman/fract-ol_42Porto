/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:23:07 by caliman           #+#    #+#             */
/*   Updated: 2024/04/24 15:24:30 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterations_julia(t_complex z, t_complex c)
{
	int		iterations;
	double	point;

	iterations = -1;
	point = 0;
	while (++iterations < MAX_ITERATIONS)
	{
		point = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = point;
		if (z.r * z.r + z.i * z.i > 4)
			return (iterations);
	}
	return (0);
}

void	calculate_z_process_pixel(t_params *params, t_complex c, t_point *point)
{
	t_complex	z;

	z.r = params->zoom * 2 * (point->x + params->x_arrow - WIDTH / 2)
		/ (WIDTH / 2);
	z.i = params->zoom * 2 * (point->y + params->y_arrow - HEIGHT / 2)
		/ (HEIGHT / 2);
	point->iterations = iterations_julia(z, c);
	pixel_color(params, point->x, point->y, point->iterations * params->color
		/ 50);
	if (point->iterations == 0)
		pixel_color(params, point->x, point->y, 0);
}

void	julia_set(t_params *params)
{
	t_complex	c;
	t_point		point;
	int			x;
	int			y;

	y = -1;
	c.r = params->real_nbr;
	c.i = params->imag_nbr;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			point.x = x;
			point.y = y;
			calculate_z_process_pixel(params, c, &point);
		}
	}
	mlx_put_image_to_window(params->mlx_ptr, params->mlx_win, params->img,
		0, 0);
}

int	iterations_mandelbrot(t_complex z)
{
	int			iterations;
	double		point;
	t_complex	c;

	iterations = -1;
	point = 0;
	c.i = z.i;
	c.r = z.r;
	while (++iterations < MAX_ITERATIONS)
	{
		point = c.r * c.r - c.i * c.i + z.r;
		c.i = 2 * c.r * c.i + z.i;
		c.r = point;
		if (c.r * c.r + c.i * c.i > 4)
			return (iterations * 40);
	}
	return (0);
}

void	mandelbrot_set(t_params *params)
{
	t_complex	z;
	int			x;
	int			y;
	int			iterations;

	x = -1;
	y = -1;
	iterations = 0;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z.r = params->zoom * 2 * (x + params->x_arrow - WIDTH / 1.6)
				/ (WIDTH / 1.6);
			z.i = params->zoom * 2 * (y + params->y_arrow - HEIGHT / 2)
				/ (HEIGHT / 2);
			iterations = iterations_mandelbrot(z);
			pixel_color(params, x, y, (iterations * 10003 * params->color));
			if (iterations == 0)
				pixel_color(params, x, y, 0);
		}
	}
	mlx_put_image_to_window(params->mlx_ptr, params->mlx_win, params->img,
		0, 0);
}
