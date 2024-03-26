/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:43:18 by caliman           #+#    #+#             */
/*   Updated: 2024/03/22 13:49:41 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char *ft_strchr(const char *str, int c)
{
    int	i;

	i = 0;
	while (str[i] != c)
	{
		if (!str[i])
			return (0);
		i++;
	}
	return ((char *)(str + i));
}

int ft_strcmp(const char *s1, const char *s2)
{
    size_t  i;

    i = 0;
    while (s1[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *res;
    int     i;
    int     j;

    i = 0;
    j = 0;
    res = (char *)malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1) * sizeof(char));
    if (!res)
        return (0);
    while (i < ft_strlen((char *)s1))
    {
        res[i] = s1[i];
        i++;
    }
    while (j < ft_strlen((char *)s2))
    {
        res[i] = s2[j];
        i++;
        j++;
    }
    res[i] = '\0';
    return (res);
}

void ft_putstr_fd(char *str, int fd)
{
    int i;

    i = 0;
    if (str)
    {
        while (str[i])
        {
            write(fd, &str[i], 1);
            i++;
        }
    }
}