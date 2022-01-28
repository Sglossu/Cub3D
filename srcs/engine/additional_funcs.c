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
		all->info.center[i] = 15000;
		all->info.sp_len[i] = -1;
		i++;
	}
}

void	sort(t_all *all, int cnt)
{
	double	tmp;
	int		p;
	int		t;

	t = 1;
	while (t)
	{
		t = 0;
		p = -1;
		while (++p + 1 < cnt)
			if (all->info.sp_len[p] > all->info.sp_len[p + 1])
			{
				tmp = all->info.sp_len[p];
				all->info.sp_len[p] = all->info.sp_len[p + 1];
				all->info.sp_len[p + 1] = tmp;
				tmp = (int)all->info.size[p];
				all->info.size[p] = all->info.size[p + 1];
				all->info.size[p + 1] = (int)tmp;
				tmp = (int)all->info.center[p];
				all->info.center[p] = all->info.center[p + 1];
				all->info.center[p + 1] = (int)tmp;
				t = 1;
			}
	}
}
