/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medoxer <medoxer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:21:37 by medoxer           #+#    #+#             */
/*   Updated: 2024/09/15 11:39:20 by medoxer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	data_init(t_map *map)
{
	map->player_path = "textures/pac_r.xpm";
	map->sleep_loop = 200000;
	map->player->speed = map->sleep_loop;
	map->player->direction = 0;
	map->player->finish = 0;
	map->player->moves = 0;
	map->player->wallet = 0;
	map->enemy->x_moving = 1;
	map->enemy->y_moving = 1;
	map->width = map->map_x * 20;
	map->height = map->map_y * 20;
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		err_no;

	err_no = 1;
	map.name = argv[0];
	map.map_path = argv[1];
	if (argc != 2 || !map_path(argv[1], &err_no)
		|| map_valide(argv[1], &err_no, &map))
		return (put_str_fd("ERROR\n", 2), ft_error(err_no), 1);
	if (map_init(&map, &err_no))
		return (put_str_fd("ERROR\n", 2), ft_error(err_no), 1);
	data_init(&map);
	if (play(&map, &err_no))
		return (ft_error(err_no), clean_up(&map), 1);
	clean_up(&map);
	return (0);
}
