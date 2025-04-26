#include "../pac_man.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	put_str_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (write (fd, &str[i], 1) == -1)
			return ;
		i++;
	}
	return ;
}
