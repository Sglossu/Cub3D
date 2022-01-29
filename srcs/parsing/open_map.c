/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:30:37 by sglossu           #+#    #+#             */
/*   Updated: 2022/01/28 21:30:38 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	map_in_array_parser(t_all *all)
{
	int	i;
	int	lines;

	lines = 0;
	while (all->map[lines] != NULL)
	{
		i = -1;
		while (all->map[lines][++i] != '\0')
		{
			if (all->map[lines][i] == 'N' || all->map[lines][i] == 'S' ||
			all->map[lines][i] == 'W' || all->map[lines][i] == 'E')
				player_detect(all, lines, i);
		}
		lines++;
	}
	if (all->ray.pa == -1)
		ft_error(7);
}

int	line_count(t_all *all, char *av, int fd)
{
	char	*line;
	int		i;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error(5);
	all->longer_string = 0;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '1' || line[0] == ' ')
		{
			if ((int)ft_strlen(line) > all->longer_string)
				all->longer_string = ft_strlen(line);
			i++;
		}
		free(line);
	}
	i += 2;
	free(line);
	line = NULL;
	return (i);
}

void	check_first_and_second_symbol(t_all *all, char *line)
{
	if (line[0] == 'R')
		resolution_parser(all, line + 1);
	if (line[0] == 'N' && line[1] == 'O')
		tex_parser(all, line + 2, 1);
	if (line[0] == 'S' && line[1] == 'O')
		tex_parser(all, line + 2, 2);
	if (line[0] == 'W' && line[1] == 'E')
		tex_parser2(all, line + 2, 3);
	if (line[0] == 'E' && line[1] == 'A')
		tex_parser2(all, line + 2, 4);
	if (line[0] == 'F')
		color_parser(all, line + 1, 'f', 0);
	if (line[0] == 'C')
		color_parser(all, line + 1, 'c', 0);
}

int	get_values(t_all *all, char *line, int *i)
{
	if (line[0] == '\0' && all->check.done != 2)
		return (1);
	check_first_and_second_symbol(all, line);
	isdone(all);
	if ((access_symbols(line[0]) || line[0] == ' ') && all->check.done)
	{
		all->check.done = 2;
		all->map[*i] = ft_strdup_modified(all, line);
		*i += 1;
	}
	else if (all->check.done == 2)
		ft_error(5);
	if (valid_keys(line[0], line[1]) == 0 && all->check.done != 2)
		ft_error(202);
	return (0);
}

void	open_map(t_all *all, char *av)
{
	char	*line;
	int		fd;
	int		i;
	int		line_cnt;

	i = 0;
	fd = if_error_open(av);
	line_cnt = line_count(all, av, fd);
	all->map = (char **)malloc(sizeof(char *) * line_cnt);
	if (!all->map)
		ft_error(10);
	while (get_next_line(fd, &line) > 0)
		get_values(all, line, &i);
	all->map[i++] = ft_strdup_modified(all, line);
	all->map[i] = NULL;
	free(line);
	line = NULL;
	error_check(all);
	map_hole_check(all, line_cnt - 2);
	map_in_array_parser(all);
}
