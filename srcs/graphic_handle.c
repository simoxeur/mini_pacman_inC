/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medoxer <medoxer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:11:36 by medoxer           #+#    #+#             */
/*   Updated: 2024/09/15 11:18:11 by medoxer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	put_texture(t_map *map, int start_x, int start_y, char *path)
{
	int	h;
	int	w;

	map->texture = mlx_xpm_file_to_image(map->mlx, path, &w, &h);
	if (!map->texture)
		return (1);
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->texture, start_x, start_y);
	mlx_destroy_image(map->mlx, map->texture);
	return (0);
}

int	put_pac(t_map *map)
{
	int	err_no;

	err_no = 0;
	if (map->player->direction == 1)
		map->player_path = "textures/pac_r.xpm";
	else if (map->player->direction == 2)
		map->player_path = "textures/pac_l.xpm";
	else if (map->player->direction == 3)
		map->player_path = "textures/pac_up.xpm";
	else if (map->player->direction == 4)
		map->player_path = "textures/pac_d.xpm";
	else
		map->player_path = "textures/pac_r.xpm";
	if (!map->player_path)
		err_no = 1;
	return (err_no);
}

int	put_subject(t_map *map, char obj, int start_x, int start_y)
{
	int	err_no;

	err_no = 0;
	if (obj == '1')
		err_no = put_texture(map, start_x, start_y, wall);
	if (obj == '0')
		err_no = put_texture(map, start_x, start_y, floor);
	if (obj == 'P')
	{
		err_no = put_pac(map);
		err_no = put_texture(map, start_x, start_y, map->player_path);
	}
	if (obj == 'C')
		err_no = put_texture(map, start_x, start_y, coins);
	if (obj == 'M' || obj == 'm')
		err_no = put_texture(map, start_x, start_y, gost);
	if (obj == 'E')
	{
		if (map->player->finish == 1)
			err_no = put_texture(map, start_x, start_y, door);
		else
			err_no = put_texture(map, start_x, start_y, floor);
	}
	return (err_no);
}

int	map_render(t_map *map, int from)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;

	i = 0;
	j = 0;
	start_x = 0;
	start_y = 0;
	while (j < map->map_y)
	{
		i = 0;
		start_x = 0;
		while (i < map->map_x)
		{
			if (!(from == 1 && (map->map[j][i] == '1'
					|| map->map[j][i] == '0' || map->map[j][i] == 'C')))
				if (put_subject(map, map->map[j][i], start_x, start_y))
					return (1);
			start_x += 20;
			i++;
		}
		start_y += 20;
		j++;
	}
	return (0);
}
