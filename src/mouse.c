/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:29:53 by caliman           #+#    #+#             */
/*   Updated: 2024/04/12 18:46:12 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_zoom(int key, int x, int y, t_params *params)
{
	(void)x;
	(void)y;
	if (key == 5)
		params->zoom *= 1.1;
	else if (key == 4)
		params->zoom /= 1.1;
	if (!ft_strcmp(params->selected_ftl, JULIA))
		julia_set(params);
	else if (!ft_strcmp(params->selected_ftl, MANDELBROT))
		mandelbrot_set(params);
	return (0);
}
