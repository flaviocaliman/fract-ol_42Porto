/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:53:53 by caliman           #+#    #+#             */
/*   Updated: 2024/04/23 11:51:21 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keys_psd(int key, t_params *params)
{
	if (key == ESC)
		close_window(params);
	if (key == PLUS)
		params->color += 1;
	if (key == MINUS && params->color - 1 > 0)
		params->color -= 1;
	if (key == ARROW_DOWN)
		params->y_arrow -= 10;
	if (key == ARROW_UP)
		params->y_arrow += 10;
	if (key == ARROW_RIGHT)
		params->x_arrow -= 10;
	if (key == ARROW_LEFT)
		params->x_arrow += 10;
	if (!ft_strcmp(params->selected_ftl, JULIA))
		julia_set(params);
	else if (!ft_strcmp(params->selected_ftl, MANDELBROT))
		mandelbrot_set(params);
	return (0);
}
