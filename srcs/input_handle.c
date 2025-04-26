#include "../pac_man.h"

int	input_handle(int key_code, t_map *map)
{
	if (key_code == right || key_code == left
		|| key_code == up || key_code == down)
		moving(map, key_code);
	if (key_code == plus)
		if ((map->player->speed - 10000) > map->sleep_loop / 4)
			map->player->speed -= 10000;
	if (key_code == mines)
		if (map->player->speed < 2 * map->sleep_loop)
			map->player->speed += 10000;
	if (key_code == echap)
		clean_up(map);
	return (0);
}
