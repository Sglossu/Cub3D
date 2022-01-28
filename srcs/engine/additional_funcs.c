/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglossu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:29:19 by sglossu           #+#    #+#             */
/*   Updated: 2022/01/28 21:29:20 by sglossu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	refresh_vars(t_all *all)
{
	int	i;

	i = 0;
	while (i <= all->cnt)
	{
		all->info.x[i] = -1;
		all->info.y[i] = -1;
		all->info.size[i] = -1;
		i++;
	}
}
