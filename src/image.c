/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:16:21 by caliman           #+#    #+#             */
/*   Updated: 2024/04/19 19:36:45 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_image(t_params *params)
{
	params->img = mlx_new_image(params->mlx_ptr, WIDTH, HEIGHT);
	if (!params->img)
	{
		ft_putstr_fd("Error -> failed to create mlx_new_image.", STDERR_FILENO);
		exit(0);
	}
	params->addr = mlx_get_data_addr(params->img, &params->bits_per_pixel,
			&params->size_line, &params->endian);
}

void	pixel_color(t_params *img, int x, int y, int iterations)
{
	char	*destiny;

	destiny = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)destiny = iterations;
}
