/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:38:21 by mbouaza           #+#    #+#             */
/*   Updated: 2022/12/23 03:50:35 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* find the position of "P" in x */

int	find_p_x(char **map, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x++])
		{
			if (map[y][x] == c)
				return (x);
		}
		y++;
	}
	return (0);
}

/* find the position of "P" in y */

int	find_p_y(char **map, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

/* itoa */

static int	ft_len(long nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

// principal function //

char	*ft_itoa(int nbr)
{
	char	*str;
	long	n;
	int		i;

	n = nbr;
	i = ft_len(n);
	if (nbr == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i--] = '\0';
	if (nbr < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

/* end of itoa */

/* to print mouvement */

void	print_count(t_game *counter, int number)
{
	char	*str;
	char	*itoa;

	itoa = NULL;
	str = NULL;
	mlx_delete_image(counter->mlx, counter->put);
	itoa = ft_itoa(number / 2);
	str = ft_s("Move : ", itoa);
	counter->put = mlx_put_string(counter->mlx, str, 25, 20);
	counter->move++;
	free(itoa);
	free(str);
}
