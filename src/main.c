/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:50:55 by caliman           #+#    #+#             */
/*   Updated: 2024/03/25 19:42:24 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw(char *name, t_params *params)
{
	if (!ft_strcmp(name, JULIA))
		julia_set(params);
	if (!ft_strcmp(name, MANDELBROT))
		mandelbrot_set(params);
}

int check_params(int nbr_params, char **av)
{
    int i;
    int j;
    
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

int main(int ac, char **av)
{
    t_params    params;

    if (check_params((ac - 1), av))
    {
        start_window(&params, ft_strjoin(av[1], " Set"));
        start_image(&params);
        if (ac == 4)
        {
            params.real_nbr = ft_atof(av[2]);
            params.imag_nbr = ft_atof(av[3]);
            params.color = 0xccf1ff;
        }
        draw(av[1], &params);
        mlx_mouse_hook(params.mlx_win, &mouse_zoom, (void*)&params);//evento relacionado ao zoom
        mlx_hook(params.mlx_win, 2, (1L << 0), &keys_psd, &params);//evento de teclado na janela
        mlx_hook(params.mlx_win, 17, 0, &close_window, 0);//evento de fechamento de janela
        mlx_loop(params.mlx_ptr);//inicia o loop de eventos gráficos e o programa continua ativo aguardando eventos
    }
    else
        instructions();
    return (0);
}
