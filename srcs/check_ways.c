#include "../pac_man.h"

char	**ft_mapcpy(t_map *map, int *err_no)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	res = (char **)malloc(map->map_y * sizeof(char *));
	if (!res)
		return (*err_no = 9, NULL);
	while (j < map->map_y)
	{
		i = 0;
		res[j] = (char *)malloc(map->map_x * sizeof(char));
		if (!res[i])
			return (ft_free_map(res, i), *err_no = 9, NULL);
		while (i < map->map_x)
		{
			res[j][i] = map->map[j][i];
			i++;
		}
		j++;
	}
	return (res);
}

int	maps_cmp(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map->map_y)
	{
		i = 0;
		while (i < map->map_x)
		{
			if (map->filled_map[j][i] == 'C' || map->filled_map[j][i] == 'E')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	check_ways(t_map *map, int *err_no)
{
	char	**map_field;

	map_field = ft_mapcpy(map, err_no);
	if (!map_field)
		return (ft_free_data(map, 2), 1);
	map->filled_map = map_field;
	flood_fill(map);
	if (maps_cmp(map))
		return (*err_no = 8, ft_free_data(map, 3), 1);
	return (0);
}
