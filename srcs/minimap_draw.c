/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:30:08 by sglossu           #+#    #+#             */
/*   Updated: 2022/01/28 21:30:09 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_rays(t_all *all)
{
	double	x;
	double	y;
	double	start;
	double	end;

	start = all->ray.pa - M_PI / 8;
	end = all->ray.pa + M_PI / 8;
	while (start <= end)
	{
		x = all->ray.px * all->scale;
		y = all->ray.py * all->scale;
		while (all->map[(int)y / all->scale][(int)x / all->scale] != '1')
		{
			x += cos(start);
			y += sin(start);
			pxl(&(all->win), x, y, 0xffffff);
		}
		start += (M_PI / 4) / (all->width / 2);
	}
}

void	draw_minimap(t_all *all, int i, int k, int color)
{
	int	x;
	int	y;

	i *= all->scale;
	k *= all->scale;
	y = 0;
	while (y++ < all->scale)
	{
		x = 0;
		while (x++ < all->scale)
			pxl(&(all->win), x + i, y + k, color);
	}
}

void	init_map_to_buffer(t_all *all)
{
	int	i;
	int	lines;

	lines = 0;
	while (all->map[lines] != NULL)
	{
		i = 0;
		while (all->map[lines][i] != '\0')
		{
			if (all->map[lines][i] == '1')
				draw_minimap(all, i, lines, 0xeba134);
			i++;
		}
		lines++;
	}
	draw_rays(all);
	mlx_put_image_to_window(all->win.mlx, all->win.mlx_win, all->win.img, 0, 0);
}
