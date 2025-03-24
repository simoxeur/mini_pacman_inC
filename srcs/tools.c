/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medoxer <medoxer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:36:20 by medoxer           #+#    #+#             */
/*   Updated: 2024/09/15 11:37:44 by medoxer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map_location(int h, int w, int *err_no)
{
	char	**map;
	int		i;

	map = (char **)malloc(h * sizeof(char *));
	if (!map)
		return (*err_no = 9, NULL);
	i = 0;
	while (i < h)
	{
		map[i] = (char *)malloc((w + 1) * sizeof(char));
		if (!map[i])
			return (*err_no = 9, ft_free_map(map, i), NULL);
		i++;
	}
	return (map);
}

char	**map_trace(int fd, int h, int w, int *err_no)
{
	char	**map;
	char	buffer[2];
	ssize_t	readed;
	int		i;
	int		j;

	map = map_location(h, w, err_no);
	if (!map)
		return (NULL);
	readed = 1;
	i = 0;
	j = 0;
	while (readed > 0)
	{
		readed = read(fd, buffer, 1);
		buffer[readed] = '\0';
		if (buffer[0] != '\n')
			map[j][i++] = buffer[0];
		else
		{
			j++;
			i = 0;
		}
	}
	return (map);
}

int	map_init(t_map *map, int *err_no)
{
	int			fd;

	map->player = malloc(sizeof(t_player));
	map->enemy = malloc(sizeof(t_enemy));
	if (!map->player || !map->enemy)
		return (*err_no = 9, 1);
	fd = open(map->map_path, O_RDONLY);
	map->map = map_trace(fd, map->map_y, map->map_x, err_no);
	if (!map->map)
		return (ft_free_data(map, 1), 1);
	if (map_valid(map, err_no))
		return (ft_free_data(map, 2), 1);
	find_player(map);
	find_enemy(map, &map->enemy->x, &map->enemy->y);
	map->map[map->enemy->y][map->enemy->x] = '0';
	if (check_ways(map, err_no))
		return (1);
	close(fd);
	return (0);
}
