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


