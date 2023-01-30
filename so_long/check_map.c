/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:43:57 by mbouaza           #+#    #+#             */
/*   Updated: 2023/01/02 10:42:43 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* check if my map is rectangular */

int	check_body(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (map[i + 1] == NULL)
		{
			if ((int)ft_strlen(map[i++]) != len - 1)
				return (error_message(0));
		}
		else if ((int)ft_strlen(map[i++]) != len)
			return (error_message(0));
	}
	return (1);
}

/* check if my map is  surrounded by wall */

int	check_wall(char **map)
{
	int	i;
	int	end_line;
	int	len;

	i = 0;
	end_line = 0;
	len = ft_strlen(map[0]) - 2;
	while (map[end_line])
		end_line++;
	end_line = end_line - 1;
	while (i < (int)ft_strlen(map[0]) - 1)
		if (map[0][i++] != '1')
			return (error_message(1));
	i = 0;
	while (i < (int)ft_strlen(map[0]) - 1)
		if (map[end_line][i++] != '1')
			return (error_message(1));
	i = 0;
	while (end_line > i++)
		if (map[i][0] != '1' || map[i][len] != '1')
			return (error_message(1));
	return (1);
}

/* check if the file of my map is a .ber */

int	check_ber(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 4] == '.' && file[i - 3] == 'b'
		&& file[i - 2] == 'e' && file[i - 1] == 'r')
		return (1);
	return (error_message(2));
}

/* check if you have more than 1 "P" and "E" and count the number of C */

int	check_double(t_game *item, char **map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	item->e = 0;
	item->p = 0;
	item->c = 0;
	while (map[y])
	{
		i = 0;
		while (map[y][i++])
		{
			if (map[y][i] == 'P')
				item->p++;
			else if (map[y][i] == 'E')
				item->e++;
			else if (map[y][i] == 'C')
				item->c++;
		}
		y++;
	}
	if (item->c >= 1 && item->p == 1 && item->e == 1)
		return (0);
	return (error_message(3));
}

/* check all potential error */

int	check_all(char **map, t_game *item)
{
	check_body(map);
	check_wall(map);
	check_has_more(map);
	check_double(item, map);
	check_is_possible(item);
	return (1);
}
