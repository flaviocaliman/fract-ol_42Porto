/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:29:53 by caliman           #+#    #+#             */
/*   Updated: 2024/03/25 19:46:19 by caliman          ###   ########.fr       */
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
