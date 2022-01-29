/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:30:21 by sglossu           #+#    #+#             */
/*   Updated: 2022/01/28 21:30:22 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	tex_parser2(t_all *all, char *s, int code)
{
	if (code == 3 && check_xpm_extension(s))
	{
		if (all->check.we)
			ft_error(101);
		while (*s == ' ')
			s += 1;
		if (open(s, O_RDONLY) < 0)
			ft_error(11);
		all->tex.w.path = ft_strdup(s);
		all->check.we = 1;
	}
	else if (code == 4 && check_xpm_extension(s))
	{
		if (all->check.ea)
			ft_error(101);
		while (*s == ' ')
			s += 1;
		if (open(s, O_RDONLY) < 0)
			ft_error(11);
		all->tex.e.path = ft_strdup(s);
		all->check.ea = 1;
	}
}

void	tex_parser(t_all *all, char *s, int code)
{
	if (code == 1 && check_xpm_extension(s))
	{
		if (all->check.no)
			ft_error(101);
		while (*s == ' ')
			s += 1;
		if (open(s, O_RDONLY) < 0)
			ft_error(11);
		all->tex.n.path = ft_strdup(s);
		all->check.no = 1;
	}
	if (code == 2 && check_xpm_extension(s))
	{
		if (all->check.so)
			ft_error(101);
		while (*s == ' ')
			s += 1;
		if (open(s, O_RDONLY) < 0)
			ft_error(11);
		all->tex.s.path = ft_strdup(s);
		all->check.so = 1;
	}
}
