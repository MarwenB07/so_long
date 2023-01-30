/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:44:04 by mbouaza           #+#    #+#             */
/*   Updated: 2023/01/30 14:51:21 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* count how many line we have for malloc my char **map */

int	count_map(char *file, t_game *count)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error_message(7));
	if (read(fd, 0, 0) < 0)
		return (error_message(7));
	line = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	free(line);
	close(fd);
	count->tabi = i;
	return (i);
}

/* copy the map.ber in a char **map */

char	**copy_map(char *file, t_game *c)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * (count_map(file, c) + 1));
	if (!map)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i++] = ft_strdup(line);
		if (!map[i - 1])
			return (free_all(map, i - 1));
		free(line);
	}
	free(line);
	map[i] = NULL;
	return (map);
}

/* just for the size x of the map */

int	msx(char **map)
{
	int	x;

	x = 0;
	while (map[0][x] == '1')
		x++;
	return (x);
}

/* just for the size y of the map */

int	msy(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

/* increase by 1 the counter of move */

void	collect_count(t_game *collect, int y, int x)
{
	collect->collect_counter++;
	collect->map[y][x] = '0';
	render_sprite(collect, x, y, "./assets/texture/floor.png");
	character_init2(collect, collect->map);
}
