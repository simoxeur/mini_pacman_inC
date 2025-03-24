/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medoxer <medoxer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:35:34 by medoxer           #+#    #+#             */
/*   Updated: 2024/09/15 11:38:53 by medoxer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
