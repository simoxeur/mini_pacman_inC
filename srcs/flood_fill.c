/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medoxer <medoxer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:06:29 by medoxer           #+#    #+#             */
/*   Updated: 2024/09/15 11:08:51 by medoxer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill(t_map *map, int pos_x, int pos_y)
{
	if (pos_x < 0 || pos_x >= map->map_x || pos_y < 0 || pos_y >= map->map_y
		|| (map->filled_map[pos_y][pos_x] != 'P'
		&& map->filled_map[pos_y][pos_x] != '0'
		&& map->filled_map[pos_y][pos_x] != 'C'
		&& map->filled_map[pos_y][pos_x] != 'E'
		&& map->filled_map[pos_y][pos_x] != 'M'))
		return ;
	map->filled_map[pos_y][pos_x] = 'F';
	fill(map, pos_x + 1, pos_y);
	fill(map, pos_x - 1, pos_y);
	fill(map, pos_x, pos_y + 1);
	fill(map, pos_x, pos_y - 1);
}

void	flood_fill(t_map *map)
{
	int	pos_x;
	int	pos_y;

	pos_x = map->player->x;
	pos_y = map->player->y;
	fill(map, pos_x, pos_y);
}
