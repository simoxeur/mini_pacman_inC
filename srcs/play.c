/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medoxer <medoxer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:34:11 by medoxer           #+#    #+#             */
/*   Updated: 2024/09/15 11:35:17 by medoxer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	play(t_map *map, int *err_no)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (*err_no = 10, 1);
	map->mlx_win = mlx_new_window(map->mlx, map->width, map->height, map->name);
	if (!map->mlx_win)
		return (*err_no = 10, 1);
	if (map_render(map, 0))
	{
		mlx_destroy_display(map->mlx);
		*err_no = 11;
		return (1);
	}
	mlx_hook(map->mlx_win, 02, 1L << 0, input_handle, map);
	mlx_hook(map->mlx_win, 17, 1L << 0, clean_up, map);
	mlx_loop_hook(map->mlx, animation, map);
	mlx_loop(map->mlx);
	return (0);
}
