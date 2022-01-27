#include "includes/cub3d.h"

void	load_textures(t_all *all)
{
	all->tex.s.img = mlx_xpm_file_to_image(all->win.mlx, all->tex.s.path,
	&all->tex.s.tex_width, &all->tex.s.tex_height);
	all->tex.s.addr = mlx_get_data_addr(all->tex.s.img,
	&all->tex.s.bits_per_pixel, &all->tex.s.line_length, &all->tex.s.endian);
	all->tex.n.img = mlx_xpm_file_to_image(all->win.mlx, all->tex.n.path,
	&all->tex.n.tex_width, &all->tex.n.tex_height);
	all->tex.n.addr = mlx_get_data_addr(all->tex.n.img,
	&all->tex.n.bits_per_pixel, &all->tex.n.line_length, &all->tex.n.endian);
	all->tex.w.img = mlx_xpm_file_to_image(all->win.mlx, all->tex.w.path,
	&all->tex.w.tex_width, &all->tex.w.tex_height);
	all->tex.w.addr = mlx_get_data_addr(all->tex.w.img,
	&all->tex.w.bits_per_pixel, &all->tex.w.line_length, &all->tex.w.endian);
	all->tex.e.img = mlx_xpm_file_to_image(all->win.mlx, all->tex.e.path,
	&all->tex.e.tex_width, &all->tex.e.tex_height);
	all->tex.e.addr = mlx_get_data_addr(all->tex.e.img,
	&all->tex.e.bits_per_pixel, &all->tex.e.line_length, &all->tex.e.endian);
	all->tex.sprite.img = mlx_xpm_file_to_image(all->win.mlx,
	all->tex.sprite.path, &all->tex.sprite.tex_width,
	&all->tex.sprite.tex_height); // delete
	all->tex.sprite.addr = mlx_get_data_addr(all->tex.sprite.img,
	&all->tex.sprite.bits_per_pixel, // delete
	&all->tex.sprite.line_length, &all->tex.sprite.endian);
}

void	start(t_all *all)
{
	all->ray.pdx = cos(all->ray.pa);
	all->ray.pdy = sin(all->ray.pa);
	draw(all);
	mlx_destroy_image(all->win.mlx, all->win.img);
	new_image(all);
}

int		main(int ac, char **av)
{
	t_all	all;

	if ((ac == 2) && check_cub_extension(av[1]))
	{
		init_struct(&all);
		init_checker(&all);
		open_map(&all, av[1]);
		all.win.mlx = mlx_init();
		all.win.mlx_win = mlx_new_window(all.win.mlx,
		all.width, all.height, "cub3d");
		new_image(&all);
		load_textures(&all);
		init_arrays(&all);
		start(&all);
		mlx_hook(all.win.mlx_win, 2, 1L << 0, &key_hook, &all);
		mlx_loop(all.win.mlx);
	}
	else
		ft_error(1);
}
