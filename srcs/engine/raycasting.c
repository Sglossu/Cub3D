#include "../../includes/cub3d.h"

double	find_side(t_all *all, int quarter, double start)
{
	while (1)
	{
		if (all->map[(int)all->ray.y][(int)all->ray.x] != '1' &&
		all->map[(int)all->ray.y][(int)all->ray.x] != '3')
			all->ray.x += 0.005 * cos(start);
		else
		{
			if (quarter == 4 || quarter == 1)
				all->side = 1;
			if (quarter == 2 || quarter == 3)
				all->side = 3;
			return (sqrt(pow(all->ray.x - all->ray.px, 2) +
			pow(all->ray.y - all->ray.py, 2)));
		}
		if (all->map[(int)all->ray.y][(int)all->ray.x] != '1' &&
		all->map[(int)all->ray.y][(int)all->ray.x] != '3')
			all->ray.y += 0.005 * sin(start);
		else
		{
			if (quarter == 1 || quarter == 2)
				all->side = 2;
			if (quarter == 3 || quarter == 4)
				all->side = 4;
			return (sqrt(pow(all->ray.x - all->ray.px, 2) +
			pow(all->ray.y - all->ray.py, 2)));
		}
	}
	return (0);
}

int		quarter_set(double start)
{
	if (fix_ang(start) >= 3 * M_PI / 2 && fix_ang(start) < 2 * M_PI)
		return (1);
	else if (fix_ang(start) >= 0 && fix_ang(start) < M_PI / 2)
		return (2);
	else if (fix_ang(start) >= M_PI / 2 && fix_ang(start) < M_PI)
		return (3);
	else if (fix_ang(start) >= M_PI && fix_ang(start) < 3 * M_PI / 2)
		return (4);
	return (0);
}

void	draw(t_all *all)
{
	int		luchi;
	int		wall;
	double	start;
	double	ray_len;

	luchi = -1;
	start = all->ray.pa - M_PI / 8;
	draw_floor(all);
	while (++luchi < all->width)
	{
		all->ray.x = all->ray.px;
		all->ray.y = all->ray.py;
		ray_len = find_side(all, quarter_set(start), fix_ang(start));
		all->info.luchi_array[luchi] = ray_len;
		wall = (int)((double)all->width / (ray_len * cos(all->ray.pa - start))); // высота картинки
		draw_3d(all, wall, luchi, 0);
		start += (M_PI / 4) / (all->width);
	}
	all->info.luchi_array[luchi] = '\0';
	refresh_vars(all);
	mlx_put_image_to_window(all->win.mlx, all->win.mlx_win, all->win.img, 0, 0);
}
