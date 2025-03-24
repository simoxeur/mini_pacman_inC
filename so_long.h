#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>
#include "mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define HEIGHT 600
#define WIDTH 600

#define left XK_Left
#define up XK_Up
#define right XK_Right
#define down XK_Down
#define plus XK_p //speed up
#define mines XK_minus //speed down
#define echap XK_Escape // close


// textures are on size (20,20)

// #define wall "textures/wall.xpm" // red walls
#define wall "textures/pac_wall1.xpm" // blue walls
#define floor "textures/black.xpm"
#define coins "textures/collect.xpm"
#define gost "textures/gost.xpm"
#define door "textures/door.xpm"
#define score "textures/score.xpm"

typedef struct s_palyer
{
    int x;
    int y;
    double len;
    int direction;
    int speed;
    int finish;
    int moves;
    int wallet;
}   t_player;

typedef struct s_enemy
{
    int x;
    int y;
    int x_moving;
    int y_moving;
}   t_enemy;

typedef struct s_map
{
    void *mlx;
    void *mlx_win;
    char **map;
    int     height;
    int     width;
    char **filled_map;
    char *name;
    char *map_path;
    char *player_path;
    int simulation_end;
    int map_x;
    int map_y;
    int started;
    int stars;
    int sleep_loop;
    t_player *player;
    t_enemy *enemy;
    void *texture;
}   t_map;

int map_path(char *map_path, int *err_no);
int map_valide(char *map, int *err_no, t_map *map_s);
int ft_error(int err_no);
char	*ft_itoa(int n);
void put_str_fd(char *str, int fd);
int map_valid(t_map *map, int *err_no);
void flood_fill(t_map *map);
int check_ways(t_map *map, int *err_no);
// int graphic_handle(t_map *map, int *err_no);
int play(t_map *map, int *err_no);
int map_render(t_map *map, int from);
int	new_map(t_map *map, char *c1, char *c2);
int put_texture(t_map *map, int start_x, int start_y, char *path);
int put_subject(t_map *map, char obj, int start_x, int start_y);
int moving(t_map *map, int key_code);
int input_handle(int key_code, t_map *map);
int animation(t_map *map);
int clean_up(t_map *map);
void    ft_free_map(char **map, int lines);
void    ft_free_data(t_map *map, int nb);
void    find_player(t_map *map);
int	find_enemy(t_map *map, int *x, int *y);
int    map_init(t_map *map, int *err_no);

#endif