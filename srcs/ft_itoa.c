/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medoxer <medoxer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:10:24 by medoxer           #+#    #+#             */
/*   Updated: 2024/09/15 11:10:40 by medoxer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static size_t	ft_count_digit(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		count++;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_str_extraction(char *str, int count, long num)
{
	while (num)
	{
		if (num < 0)
		{
			num = -num;
			str[0] = '-';
		}
		str[count] = '0' + (num % 10);
		count--;
		num = num / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	num;
	int		count;
	char	*str;

	num = n;
	count = ft_count_digit(num);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[count--] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	str = ft_str_extraction(str, count, num);
	return (str);
}
