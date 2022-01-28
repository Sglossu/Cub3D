/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:29:46 by sglossu           #+#    #+#             */
/*   Updated: 2022/01/28 21:29:47 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_error(int code)
{
	if (code == 0)
		write(1, "Bad resolution set\n", 19);
	if (code == 1)
		write(1, "Wrong number of arguments\n", 22);
	if (code == 2)
		write(1, "Bad map extension. Must be '.cub'\n", 34);
	if (code == 3)
		write(1, "Bad texture extension\n", 22);
	if (code == 4)
		write(1, "Bad color set\n", 14);
	if (code == 5)
		write(1, "The map isn't closed or not corrected\n", 38);
	if (code == 6)
		write(1, "Not access symbols in map\n", 26);
	if (code == 7)
		write(1, "No player in the map\n", 21);
	if (code == 8)
		write(1, "Map is directory\n", 17);
//	if (code == 9)
//		write(1, "\n", );
	if (code == 10)
		write(1, "Error with memory allocation\n", 29);
	if (code == 77)
		write(1, "Two player in map\n", 18);
	if (code == 99)
		write(1, "Fail third argument\n", 20);
	if (code == 101)
		write(1, "Duplicate parameters\n", 21);
	if (code == 202)
		write(1, "Trash in file\n", 14);
	exit(code);
}

void	error_check(t_all *all)
{
	if (all->tex.e.path == NULL || all->tex.n.path == NULL ||
	all->tex.s.path == NULL || all->tex.w.path == NULL)
		ft_error(3);
	(all->tex.floor_color == 0 || all->tex.ceiling_color == 0) ?
		ft_error(4) : 0;
	(all->width <= 0 || all->height <= 0) ? ft_error(0) : 0;
}
