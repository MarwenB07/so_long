/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:10:59 by mbouaza           #+#    #+#             */
/*   Updated: 2022/12/23 15:49:00 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_c(char **map)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	y = 0;
	c = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

int	*search_is_p(char **map, int x, int y, char c)
{
	static int	end[2] = {0, 0};
	static int	s_x;
	static int	s_y;

	s_x = msx(map);
	s_y = msy(map);
	if (y < 0 || y >= s_y || x < 0 || x >= s_x
		|| map[y][x] == c || map[y][x] == 'G')
		return (NULL);
	if (map[y][x] == 'E')
		end[1] += 1;
	else if (map[y][x] == 'C')
		end[0] += 1;
	map[y][x] = c;
	search_is_p(map, x + 1, y, c);
	search_is_p(map, x, y + 1, c);
	search_is_p(map, x, y - 1, c);
	search_is_p(map, x - 1, y, c);
	return (end);
}

int	test_item(char c)
{
	if (c == '0')
		return (1);
	else if (c == '1')
		return (1);
	else if (c == 'P')
		return (1);
	else if (c == 'E')
		return (1);
	else if (c == 'C')
		return (1);
	else if (c == 'G')
		return (1);
	return (-1);
}

int	check_has_more(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (x != msx(map))
		{
			if (test_item(map[y][x]) == -1)
			{
				return (error_message(6));
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_is_possible(t_game *t)
{
	char	**map;
	int		*check;
	int		x;
	int		y;
	int		c;

	c = count_c(t->map);
	x = find_p_x(t->map, 'P');
	y = find_p_y(t->map, 'P');
	map = copy_map_2(t->map);
	if (!map)
		return (error_message(5));
	check = search_is_p(map, x, y, '1');
	free(map);
	if (check[0] == c && check[1] == 1)
		return (1);
	return (error_message(4));
}
