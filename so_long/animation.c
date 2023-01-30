/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:12:56 by mbouaza           #+#    #+#             */
/*   Updated: 2023/01/30 14:40:59 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* make all animation sprite */

void	portal(void *param)
{
	t_game			*cb;
	mlx_texture_t	*txt;
	static int		x;
	static int		y;
	static int		comp = 0;

	if (++comp <= 6)
		return ;
	cb = param;
	mlx_delete_image(cb->mlx, cb->portail);
	x = find_p_x(cb->map, 'E');
	y = find_p_y(cb->map, 'E');
	txt = mlx_load_png(ft_s(ft_s("./assets/po/p_", ft_itoa(cb->i)), ".png"));
	cb->portail = mlx_texture_to_image(cb->mlx, txt);
	mlx_image_to_window(cb->mlx, cb->portail, x * S, y * S);
	mlx_set_instance_depth(&cb->portail->instances[0], 80);
	if (++cb->i == 6)
		cb->i = 0;
	comp = 0;
}

/* re-load my character (guts) */

void	character_init2(t_game *s, char **map)
{
	int	i;

	i = 0;
	i = ft_strlen(map[i]);
	mlx_delete_image(s->mlx, s->guts);
	if (s->p_o == 0)
		s->texture = mlx_load_png("./assets/character/guts_2.png");
	else
		s->texture = mlx_load_png("./assets/character/guts.png");
	s->guts = mlx_texture_to_image(s->mlx, s->texture);
	mlx_image_to_window(s->mlx, s->guts, s->p_x * S, s->p_y * S);
}

/* check have enought C */

int	win_rule(t_game *win)
{
	if (win->collect_counter == win->c)
	{
		win->exit = 1;
		return (win_game(win));
	}
	return (1);
}
