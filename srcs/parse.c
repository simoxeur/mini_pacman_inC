#include "../pac_man.h"

static int	ber_cmp(char *extention)
{
	return (extention[0] == 'b' && extention[1] == 'e' && extention[2] == 'r');
}

static int	comp_exist(char c, int *err_no)
{
	if ((c == '0' || c == '1' || c == 'P' || c == 'C'
			|| c == 'E' || c == 'M' || c == '\n'
			|| c == '\0') && *err_no != 4 && *err_no != 5)
		*err_no = 0;
	else
		*err_no = 5;
	return (0);
}

static int	fl_read(int fd, int *h, int *w, int *err_no)
{
	int		i;
	ssize_t	readed;
	char	buffer[2];

	i = 0;
	readed = 1;
	while (readed)
	{
		readed = read(fd, buffer, 1);
		buffer[readed] = '\0';
		comp_exist(buffer[0], err_no);
		if (buffer[0] != '\n' && buffer[0] != '\0')
			i++;
		if (buffer[0] == '\n' || buffer[0] == '\0')
		{
			++*h;
			if (*w >= 0 && *w != i)
				return (*err_no = 4, 1);
			*w = i;
			i = 0;
		}
	}
	return (*err_no);
}

int	map_path(char *map_path, int *err_no)
{
	if (map_path[0] == '.')
		return (0);
	while (*map_path != '.')
		map_path++;
	if (*map_path == '.')
		return (*err_no = 2, ber_cmp(++map_path));
	return (0);
}

int	map_valide(char *map, int *err_no, t_map *map_s)
{
	int	fd;
	int	h;
	int	w;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (*err_no = 3, 1);
	h = 0;
	w = -1;
	if (fl_read(fd, &h, &w, err_no))
		return (close(fd), 1);
	map_s->map_x = w;
	map_s->map_y = h;
	close(fd);
	return (0);
}
