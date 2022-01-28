/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:31:09 by sglossu           #+#    #+#             */
/*   Updated: 2022/01/28 21:31:11 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strdup_modified(t_all *all, const char *str)
{
	int		i;
	char	*copy;

	i = 0;
	copy = malloc(sizeof(char) * (all->longer_string + 1));
	if (!copy)
		ft_error(10);
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	while (i < all->longer_string)
		copy[i++] = ' ';
	copy[i] = '\0';
	return (copy);
}

int	no_clip(t_all *all, int a)
{
	double	temppx;
	double	temppy;
	char	c;

	temppx = all->ray.px;
	temppy = all->ray.py;
	if (a == 1)
	{
		temppx += all->ray.pdx * 0.5;
		temppy += all->ray.pdy * 0.5;
	}
	else if (a == 2)
	{
		temppx -= all->ray.pdx * 0.5;
		temppy -= all->ray.pdy * 0.5;
	}
	else if (a == 3 || a == 4)
		no_clip2(all, a, &temppx, &temppy);
	c = all->map[(int)(temppy)][(int)(temppx)];
	if (c == '0' || c == 'S' || c == 'E' || c == 'W' || c == 'N')
		return (1);
	else
		return (0);
}

int	check_xpm_extension(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (i >= 4 && (s[i - 1] == 'm' || s[i - 1] == 'M') && \
	(s[i - 2] == 'p' || s[i - 2] == 'P') && \
	(s[i - 3] == 'x' || s[i - 3] == 'X') && \
	(s[i - 4] == '.' || s[i - 4] == '.'))
		return (1);
	else
		ft_error(3);
	return (0);
}

int	check_cub_extension(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len >= 4 && s[len - 1] == 'b' && s[len - 2] == 'u' \
	&& s[len - 3] == 'c' && s[len - 4] == '.')
		return (1);
	else
		ft_error(2);
	return (0);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
