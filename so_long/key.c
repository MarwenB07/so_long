/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:24:44 by mbouaza           #+#    #+#             */
/*   Updated: 2023/01/30 14:46:21 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* load my character (Guts) */

void	character_init(t_game *s, char **map)
{
	int	i;

	i = 0;
	s->p_x = find_p_x(map, 'P');
	s->p_y = find_p_y(map, 'P');
	i = ft_strlen(map[i]);
	s->put = mlx_put_string(s->mlx, "Move : 0", 25, 20);
	s->move++;
	if (i / 2 > s->p_x)
		s->texture = mlx_load_png("./assets/character/guts_2.png");
	else
		s->texture = mlx_load_png("./assets/character/guts.png");
	s->guts = mlx_texture_to_image(s->mlx, s->texture);
	mlx_image_to_window(s->mlx, s->guts, s->p_x * S, s->p_y * S);
}

/* mouvement and count */

void	move_pos_x(t_game *run)
{
	run->guts->instances[0].x += 1 * S;
	run->p_x += 1;
	run->p_o = 0;
	character_init2(run, run->map);
	print_count(run, (run->move++));
}

void	move_neg_x(t_game *run)
{
	run->guts->instances[0].x -= 1 * S;
	run->p_x -= 1;
	run->p_o = 1;
	character_init2(run, run->map);
	print_count(run, (run->move++));
}

void	move_pos_y(t_game *run)
{
	run->guts->instances[0].y += 1 * S;
	run->p_y += 1;
	print_count(run, (run->move++));
}

void	move_neg_y(t_game *run)
{
	run->guts->instances[0].y -= 1 * S;
	run->p_y -= 1;
	print_count(run, (run->move++));
}

/* End */
