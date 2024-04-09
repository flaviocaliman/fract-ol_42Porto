/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:16:21 by caliman           #+#    #+#             */
/*   Updated: 2024/04/04 22:10:09 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void start_image(t_params *params)
{
    params->img = mlx_new_image(params->mlx_ptr, WIDTH, HEIGHT);
    if (!params->img)
    {
        ft_putstr_fd("Error -> failed to create mlx_new_image.", STDERR_FILENO);
        exit(0);
    }
    params->addr = mlx_get_data_addr(params->img, &params->bits_per_pixel, &params->size_line, &params->endian);
}
