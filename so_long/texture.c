/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:56:57 by mbouaza           #+#    #+#             */
/*   Updated: 2023/01/30 15:21:06 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* place a sprit */

void	render_sprite(t_game *sprit, int x, int y, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	img = mlx_texture_to_image(sprit->mlx, texture);
	mlx_image_to_window(sprit->mlx, img, x * S, y * S);
}

/* choose random asset for floor */

static void	floor(t_game *sprit, int x, int y)
{
	int	random;

	random = 0;
	if (random == 5)
		render_sprite(sprit, x, y, "./assets/texture/floor_alter2.png");
	else if (random == 7)
		render_sprite(sprit, x, y, "./assets/texture/floor_alter3.png");
	else if (random == 25)
		render_sprite(sprit, x, y, "./assets/texture/floor_alter1.png");
	else
		render_sprite(sprit, sprit->x, sprit->y, "./assets/texture/floor.png");
	sprit->random++;
}

void	render_sprite_light(t_game *sprit, int x, int y, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	img = mlx_texture_to_image(sprit->mlx, texture);
	mlx_image_to_window(sprit->mlx, img, x * S, y * S);
	mlx_delete_image(sprit->mlx, img);
}

/* create the map and all texture */

void	create_map(t_game *s, char **map)
{
	while (map[s->y])
	{
		s->x = 0;
		while (map[s->y][s->x])
		{
			if (map[s->y][s->x] == '0')
				floor(s, s->x, s->y);
			else if (map[s->y][s->x] == '1')
				render_sprite(s, s->x, s->y, "./assets/texture/wall.png");
			else if (map[s->y][s->x] == 'P')
				render_sprite(s, s->x, s->y, "./assets/texture/spawn.png");
			else if (map[s->y][s->x] == 'E')
				render_sprite(s, s->x, s->y, "./assets/exit/portail_0.png");
			else if (map[s->y][s->x] == 'C')
				render_sprite(s, s->x, s->y, "./assets/c/b_0.png");
			else if (map[s->y][s->x] == 'G')
				render_sprite(s, s->x, s->y, "./assets/g/g_0.png");
			s->x++;
		}
		s->y += 1;
	}
}
