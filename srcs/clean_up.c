#include "../pac_man.h"

void	ft_free_map(char **map, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_data(t_map *map, int nb)
{
	free(map->player);
	free(map->enemy);
	if (nb > 1)
		ft_free_map(map->map, map->map_y);
	if (nb > 2)
		ft_free_map(map->filled_map, map->map_y);
}

int	clean_up(t_map *map)
{
	if (map && map->mlx && map->mlx_win && map->texture)
	{
		mlx_clear_window(map->mlx, map->mlx_win);
		mlx_destroy_window(map->mlx, map->mlx_win);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	ft_free_data(map, 3);
	exit(0);
	return (0);
}
