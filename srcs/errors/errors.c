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

void	ft_error_else(int code)
{
	if (code == 77)
		write(1, "Two player in map\n", 18);
	else if (code == 99)
		write(1, "Fail third argument\n", 20);
	else if (code == 101)
		write(1, "Duplicate parameters\n", 21);
	else if (code == 202)
		write(1, "Garbage in file\n", 14);
}

void	ft_error(int code)
{
	if (code == 0)
		write(1, "Bad resolution set\n", 19);
	else if (code == 1)
		write(1, "Wrong number of arguments\n", 22);
	else if (code == 2)
		write(1, "Bad map extension. Must be '.cub'\n", 34);
	else if (code == 3)
		write(1, "Bad texture extension\n", 22);
	else if (code == 4)
		write(1, "Bad color set\n", 14);
	else if (code == 5)
		write(1, "The map isn't closed or not corrected\n", 38);
	else if (code == 6)
		write(1, "Not access symbols in map\n", 26);
	else if (code == 7)
		write(1, "No player in the map\n", 21);
	else if (code == 8)
		write(1, "Map is directory\n", 17);
	else if (code == 10)
		write(1, "Error with memory allocation\n", 29);
	else
		ft_error_else(code);
	exit(code);
}

void	error_check(t_all *all)
{
	if (all->tex.e.path == NULL || all->tex.n.path == NULL || \
	all->tex.s.path == NULL || all->tex.w.path == NULL)
		ft_error(3);
	if (all->tex.floor_color == 0 || all->tex.ceiling_color == 0)
		ft_error(4);
	if (all->width <= 0 || all->height <= 0)
		ft_error(0);
}

int	if_error_open(char *av)
{
	int	fd;

	fd = open(av, O_DIRECTORY);
	if (fd != -1)
		ft_error(8);
	close(fd);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error(11);
	return (fd);
}
