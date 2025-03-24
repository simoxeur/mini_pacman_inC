/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medoxer <medoxer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:23:52 by medoxer           #+#    #+#             */
/*   Updated: 2024/09/15 11:24:25 by medoxer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_component(t_map *map, int *err_no)
{
	int	player;
	int	collect;
	int	exit_door;
	int	i;
	int	j;

	player = 0;
	collect = 0;
	exit_door = 0;
	i = 0;
	j = 0;
	while (j < map->map_y)
	{
		i = 0;
		while (i < map->map_x)
		{
			if (map->map[j][i] == 'P')
				player++;
			if (map->map[j][i] == 'C')
				collect++;
			if (map->map[j][i] == 'E')
				exit_door++;
			i++;
		}
		j++;
	}
	map->stars = collect;
	if (player != 1 || collect == 0 || exit_door != 1)
		return (*err_no = 7, 1);
	return (0);
}

int	map_valid(t_map *map, int *err_no)
{
	int	i;

	i = 0;
	while (i < map->map_x)
	{
		if (map->map[0][i] != '1')
			return (*err_no = 6, 1);
		i++;
	}
	i = 0;
	while (i < map->map_x)
	{
		if (map->map[map->map_y - 1][i] != '1')
			return (*err_no = 6, 1);
		i++;
	}
	i = 0;
	while (i < map->map_y)
	{
		if (map->map[i][0] != '1' || map->map[i][map->map_x - 1] != '1')
			return (*err_no = 6, 1);
		i++;
	}
	return (check_component(map, err_no));
}
