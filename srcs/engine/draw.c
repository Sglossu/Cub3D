#include "../../includes/cub3d.h"

void	init_3d_vars(t_all *all, double *iter, double *mx, int wall)
{
	if (all->side == 1)
		*iter = (double)all->tex.n.tex_height / (double)wall;
	if (all->side == 2)
		*iter = (double)all->tex.e.tex_height / (double)wall;
	if (all->side == 3)
		*iter = (double)all->tex.s.tex_height / (double)wall;
	if (all->side == 4)
		*iter = (double)all->tex.w.tex_height / (double)wall;
	if (all->side == 1)
		*mx = (all->ray.x - (int)all->ray.x) * all->tex.n.tex_width;
	if (all->side == 2)
		*mx = (all->ray.y - (int)all->ray.y) * all->tex.e.tex_width;
	if (all->side == 3)
		*mx = all->tex.s.tex_width -
			(all->ray.x - (int)all->ray.x) * all->tex.s.tex_width;
	if (all->side == 4)
		*mx = all->tex.w.tex_width - (all->ray.y -
			(int)all->ray.y) * all->tex.w.tex_width;
}

void	draw_3d(t_all *all, int wall, int luchi, double k)
{
	int		start;
	int		end;
	int		color;
	double	iter;
	double	mx;

	start = all->height / 2 - wall / 2;
	end = all->height / 2 + wall / 2;
	init_3d_vars(all, &iter, &mx, wall);
	while (start++ < 0)
		k += iter;
	while (start < end && start < all->height)
	{
		if (all->side == 1)
			color = get_color(&(all->tex.n), mx, k);
		else if (all->side == 2)
			color = get_color(&(all->tex.e), mx, k);
		else if (all->side == 3)
			color = get_color(&(all->tex.s), mx, k);
		else
			color = get_color(&(all->tex.w), mx, k);
		pxl(&(all->win), luchi, start++, color);
		k += iter;
	}
}

void	draw_floor(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (++i < all->width)
	{
		j = all->height / 2;
		while (j < all->height)
			pxl(&(all->win), i, j++, all->tex.floor_color);
	}
	i = -1;
	while (++i < all->width)
	{
		j = 0;
		while (j < all->height / 2)
			pxl(&(all->win), i, j++, all->tex.ceiling_color);
	}
	mlx_put_image_to_window(all->win.mlx, all->win.mlx_win, all->win.img, 0, 0);
}
