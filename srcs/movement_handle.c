/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medoxer <medoxer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:25:14 by medoxer           #+#    #+#             */
/*   Updated: 2024/09/15 11:30:37 by medoxer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	new_map(t_map *map, char *c1, char *c2)
{
	char	tmp;

	if (!map)
		return (1);
	if (*c2 == 'C')
	{
		map->player->wallet++;
		if (map->player->wallet == map->stars)
		{
			map->player->finish = 1;
			map_render(map, 1);
		}
		*c2 = '0';
	}
	if (*c2 == '1')
		return (1);
	if (*c2 == 'E' && map->player->finish == 1)
		return (2);
	if (*c2 == 'M')
		return (3);
	tmp = 0;
	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
	return (0);
}

void	player_direction(t_map *map, int key_code)
{
	if (key_code == right)
		map->player->direction = 1;
	if (key_code == left)
		map->player->direction = 2;
	if (key_code == up)
		map->player->direction = 3;
	if (key_code == down)
		map->player->direction = 4;
}

int	move_and_check(t_map *map, int key_code, int err_no)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = map->player->x;
	tmp_y = map->player->y;
	if (err_no == 1)
		return (1);
	if (err_no == 2)
	{
		printf("succes\n");
		clean_up(map);
	}
	if (err_no == 3)
	{
		printf("died\n");
		clean_up(map);
	}
	if (key_code == right || key_code == left
		|| key_code == up || key_code == down)
	{
		map_render(map, 1);
		put_subject(map, '0', tmp_x * 20, tmp_y * 20);
	}
	return (0);
}

int	moving(t_map *map, int key_code)
{
	int	err_no;
	int	tmp_direction;

	tmp_direction = map->player->direction;
	player_direction(map, key_code);
	find_player(map);
	err_no = 0;
	if (key_code == right)
		err_no = new_map(map, &map->map[map->player->y][map->player->x],
				&map->map[map->player->y][map->player->x + 1]);
	if (key_code == left)
		err_no = new_map(map, &map->map[map->player->y][map->player->x],
				&map->map[map->player->y][map->player->x - 1]);
	if (key_code == up)
		err_no = new_map(map, &map->map[map->player->y][map->player->x],
				&map->map[map->player->y - 1][map->player->x]);
	if (key_code == down)
		err_no = new_map(map, &map->map[map->player->y][map->player->x],
				&map->map[map->player->y + 1][map->player->x]);
	if (move_and_check(map, key_code, err_no))
		return (map->player->direction = tmp_direction, 1);
	map->player->moves++;
	return (0);
}

void	find_player(t_map *map)
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
			if (map->map[j][i] == 'P')
			{
				map->player->x = i;
				map->player->y = j;
			}
			i++;
		}
		j++;
	}
}

int	find_enemy(t_map *map, int *x, int *y)
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
			if (map->map[j][i] == 'M')
			{
				*x = i;
				*y = j;
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}