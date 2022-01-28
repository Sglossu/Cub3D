/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:31:24 by sglossu           #+#    #+#             */
/*   Updated: 2022/01/28 21:31:25 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	no_clip2(t_all *all, int a, double *temppx, double *temppy)
{
	if (a == 3)
	{
		*temppx += all->ray.pdy * 0.3;
		*temppy -= all->ray.pdx * 0.3;
	}
	else if (a == 4)
	{
		*temppx -= all->ray.pdy * 0.3;
		*temppy += all->ray.pdx * 0.3;
	}
}

void	new_image(t_all *all)
{
	all->win.img = mlx_new_image(all->win.mlx, all->width, all->height);
	all->win.addr = mlx_get_data_addr(all->win.img, &all->win.bits_per_pixel, \
	&all->win.line_length, &all->win.endian);
}

int	ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					ink;
	unsigned long int	num;

	i = 0;
	ink = 1;
	num = 0;
	if (!str[i])
		return (0);
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' \
	|| str[i] == '\f' || str[i] == ' ' || str[i] == '\r')
		i += 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			ink = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	if (num > 9223372036854775807 && ink > 0)
		return (-1);
	else if (num > 9223372036854775807 && ink < 0)
		return (0);
	return (num * ink);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*copy;

	i = 0;
	while (str[i] != '\0')
		i++;
	copy = malloc(i + 1);
	if (!copy)
		exit(0);
	i = 0;
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
