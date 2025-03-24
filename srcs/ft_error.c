/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medoxer <medoxer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:09:28 by medoxer           #+#    #+#             */
/*   Updated: 2024/09/15 11:09:39 by medoxer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_error(int err_no)
{
	if (err_no == 1)
		put_str_fd("usage: \033[0;32m./so_long pathmap.ber\n", 2);
	if (err_no == 2)
		put_str_fd("the file should be in this form: name.ber\n", 2);
	if (err_no == 3)
		put_str_fd("\033[0;31mmap path not valid\n", 2);
	if (err_no == 4)
		put_str_fd("the map should be rectangle and not empty\n", 2);
	if (err_no == 5)
		put_str_fd("there is undefined character\n", 2);
	if (err_no == 6)
		put_str_fd("the map should tourned by 1 as wall\n", 2);
	if (err_no == 7)
		put_str_fd("the map should contain :\none player P, \
one exit door E and at least one collectible C\n", 2);
	if (err_no == 8)
		put_str_fd("the player P should have a way between him and \
the the collectibles and the exit door\n", 2);
	if (err_no == 9)
		put_str_fd("malloc failed\n", 2);
	if (err_no == 10)
		put_str_fd("mlx failed\n", 2);
	if (err_no == 11)
		put_str_fd("an image path is invalide\n", 2);
	return (1);
}
