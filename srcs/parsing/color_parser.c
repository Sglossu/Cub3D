/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:37:50 by sglossu           #+#    #+#             */
/*   Updated: 2022/01/28 22:37:52 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_ceiling_color(t_all *all, int r, int g, int b)
{
	all->tex.ceiling_color = rgb_to_hex(r, g, b);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_error(4);
	all->check.c = 1;
}

void	ft_floor_color(t_all *all, int r, int g, int b)
{
	all->tex.floor_color = rgb_to_hex(r, g, b);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		ft_error(4);
	all->check.f = 1;
}

void	set_gb(int *g, int *b, int i, char *s)
{
	if (i == 1)
		*g = ft_atoi(s);
	if (i == 2)
		*b = ft_atoi(s);
}

void	color_parser(t_all *all, char *s, char c, int i)
{
	int	r;
	int	g;
	int	b;

	r = -1;
	g = -1;
	b = -1;
	if ((c == 'f' && all->check.f) || (c == 'c' && all->check.c))
		ft_error(101);
	while (*s != '\0')
	{
		while (!ft_isdigit(*s))
			s += 1;
		if (!i)
			r = ft_atoi(s);
		else
			set_gb(&g, &b, i, s);
		while (ft_isdigit(*s))
			s += 1;
		i++;
	}
	if (c == 'c')
		ft_ceiling_color(all, r, g, b);
	else if (c == 'f')
		ft_floor_color(all, r, g, b);
}
