/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:50:55 by caliman           #+#    #+#             */
/*   Updated: 2024/04/23 11:53:35 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(char *name, t_params *params)
{
	if (!ft_strcmp(name, JULIA))
		julia_set(params);
	if (!ft_strcmp(name, MANDELBROT))
		mandelbrot_set(params);
}

int	check_params(int nbr_params, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (nbr_params == 1 && !ft_strcmp(av[1], MANDELBROT))
	{
		return (1);
	}
	else if (nbr_params == 3 && !ft_strcmp(av[1], JULIA))
	{
		while (++j < nbr_params)
		{
			i = 0;
			while (av[j][i])
				if (ft_strchr(DEC_BASE, av[j][i++]))
					return (1);
		}
	}
	else
		return (0);
	return (0);
}

void	cleanup(t_params *params)
{
	if (params->mlx_win)
		mlx_destroy_window(params->mlx_ptr, params->mlx_win);
	if (params->img)
		mlx_destroy_image(params->mlx_ptr, params->img);
	if (params->mlx_ptr)
		mlx_destroy_display(params->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_params	params;
	char		*str;

	if (check_params((ac - 1), av))
	{
		str = ft_strjoin(av[1], " Set");
		start_window(&params, str);
		free(str);
		start_image(&params);
		if (ac == 4)
		{
			params.real_nbr = ft_atof(av[2]);
			params.imag_nbr = ft_atof(av[3]);
			params.color = 0xccf1ff;
		}
		draw(av[1], &params);
		mlx_mouse_hook(params.mlx_win, &mouse_zoom, (void *)&params);
		mlx_hook(params.mlx_win, 2, (1L << 0), &keys_psd, &params);
		mlx_hook(params.mlx_win, 17, 0, &close_window, &params);
		mlx_loop(params.mlx_ptr);
	}
	else
		instructions();
	return (0);
}
