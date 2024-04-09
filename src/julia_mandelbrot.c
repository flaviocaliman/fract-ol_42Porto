/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:23:07 by caliman           #+#    #+#             */
/*   Updated: 2024/04/04 22:47:18 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void pixel_color(t_params *img, int x, int y, int iterations)
{
	char	*destiny;

	destiny = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int*)destiny = iterations;
}

int		iterations_julia(complex z, complex c)
{
	int		i;
	double	point;

	i = -1;
	point = 0;
	while (++i < MAX_ITERATIONS)
	{
		point = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = point;
		if (z.r * z.r + z.i * z.i > 4)
			return (i);
	}
	return (0);
}

void	julia_set(t_params *params)
{
	complex	z;
	complex	c;
	int		x;
	int		y;
	int		iterations;

	x = -1;
	y = -1;
	c.r = params->real_nbr;
	c.i = params->imag_nbr;
	iterations = 0;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z.r = params->zoom * 2 * (x + params->x_arrow - WIDTH / 2) / (WIDTH / 2);
			z.i = params->zoom * 2 * (y + params->y_arrow - HEIGHT / 2) / (HEIGHT / 2);
			iterations = iterations_julia(z, c);
			pixel_color(params, x, y, iterations * params->color / 200);
			if (iterations == 0)
				pixel_color(params, x, y, 0);
		}
	}
	mlx_put_image_to_window(params->mlx_ptr, params->mlx_win, params->img, 0, 0);
}

int		iterations_mandelbrot(complex z)
{
	int		i;
	double	point;
	complex	c;

	i = -1;
	point = 0;
	c.i = z.i;
	c.r = z.r;
	while (++i < MAX_ITERATIONS)
	{
		point = c.r * c.r - c.i * c.i + z.r;
		c.i = 2 * c.r * c.i + z.i;
		c.r = point;
		if (c.r * c.r + c.i * c.i > 4)
			return (i * 40);
	}
	return (0);
}

void	mandelbrot_set(t_params *params)
{
	complex	z;
	int		x;
	int		y;
	int		iterations;

	x = -1;
	y = -1;
	iterations = 0;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z.r = params->zoom * 2 * (x + params->x_arrow - WIDTH / 1.6) / (WIDTH / 1.6);
			z.i = params->zoom * 2 * (y + params->y_arrow- HEIGHT / 2) / (HEIGHT / 2);
			iterations = iterations_mandelbrot(z);
			pixel_color(params, x, y, (iterations * 10003 * params->color));
			if (iterations == 0)
				pixel_color(params, x, y, 0);
		}
	}
	mlx_put_image_to_window(params->mlx_ptr, params->mlx_win, params->img, 0, 0);
}
