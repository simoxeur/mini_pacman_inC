#include "../pac_man.h"

void	enemy_animation(t_map *map)
{
	int dir = (map->enemy->x_moving == 1) ? 1 : -1;
	int new_x = map->enemy->x + dir;
	map->enemy->x += dir;

	if (map->map[map->enemy->y][new_x] == 'P' || (map->enemy->x == map->player->x && map->enemy->y == map->player->y))
	{
			printf("died\n");
			clean_up(map);
	}
	else if (map->map[map->enemy->y][new_x] != '1' && map->map[map->enemy->y][new_x] != 'E')
	{
		put_subject(map, 'M', new_x * 20, map->enemy->y * 20);

		if (map->map[map->enemy->y][new_x - dir] == 'C')
			put_subject(map, 'C', (new_x - dir) * 20, map->enemy->y * 20);
		if (map->map[map->enemy->y][new_x - dir] == '0')
			put_subject(map, '0', (new_x - dir) * 20, map->enemy->y * 20);
	}
	else
		map->enemy->x_moving = !(map->enemy->x_moving);
	usleep(map->player->speed / 10);
	return ;
}

int	player_animation(t_map *map)
{
	usleep(map->player->speed);
	if (map->player->direction == 0)
		return (0);
	if (map->player->direction == 1)
		moving(map, right);
	if (map->player->direction == 2)
		moving(map, left);
	if (map->player->direction == 3)
		moving(map, up);
	if (map->player->direction == 4)
		moving(map, down);
	return (0);
}

int	animation(t_map *map)
{
	char	*wallet;

	wallet = ft_itoa(map->player->wallet);
	if (put_texture(map, 14 * 20, 0 * 20, score))
		return (put_str_fd("ERROR\nscore background failed to reach\n", 2),
			clean_up(map));
	mlx_string_put(map->mlx, map->mlx_win, 15 * 20 - 5, 25, 0XFFFFFF, wallet);
	free(wallet);
	player_animation(map);
	enemy_animation(map);
	return (0);
}
