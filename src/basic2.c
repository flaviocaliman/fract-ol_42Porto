/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:31:03 by caliman           #+#    #+#             */
/*   Updated: 2024/04/19 19:18:49 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb *= i;
		power--;
	}
	return (nb);
}

int	ft_check_white_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	return (i);
}

int	check_signal(const char *str, int *i)
{
	int	signal;

	signal = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			signal = signal * -1;
		(*i)++;
	}
	return (signal);
}

double	ft_atof(const char *str)
{
	int		i;
	int		signal;
	double	res;
	int		div;

	i = ft_check_white_space((char *)str);
	signal = check_signal(str, &i);
	res = 0;
	div = i;
	while (str[i] == '.' || (str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] != '.')
		{
			res = res * 10 + str[i] - 48;
			i++;
		}
		else
		{
			div = i;
			i++;
		}
	}
	return (res * signal / ft_iterative_power(10, (i - div - 1)));
}
