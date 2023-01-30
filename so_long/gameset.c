/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:23:03 by mbouaza           #+#    #+#             */
/*   Updated: 2022/12/23 04:13:19 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	m_is_xp(t_game *po)
{
	if (po->map[po->p_y][po->p_x + 1] == '1')
	{
		po->p_o = 0;
		character_init2(po, po->map);
		return (0);
	}
	else if (po->map[po->p_y][po->p_x + 1] == 'G')
		return (game_over(po));
	else if (po->map[po->p_y][po->p_x + 1] == 'C')
		collect_count(po, po->p_y, po->p_x + 1);
	else if (po->map[po->p_y][po->p_x + 1] == 'E')
		win_rule(po);
	return (1);
}

int	m_is_xn(t_game *po)
{
	if (po->map[po->p_y][po->p_x - 1] == '1')
	{
		po->p_o = 1;
		character_init2(po, po->map);
		return (0);
	}
	else if (po->map[po->p_y][po->p_x - 1] == 'G')
		return (game_over(po));
	else if (po->map[po->p_y][po->p_x - 1] == 'C')
		collect_count(po, po->p_y, po->p_x - 1);
	else if (po->map[po->p_y][po->p_x - 1] == 'E')
		win_rule(po);
	return (1);
}

int	m_is_yp(t_game *po)
{
	if (po->map[po->p_y + 1][po->p_x] == '1')
		return (0);
	else if (po->map[po->p_y + 1][po->p_x] == 'G')
		return (game_over(po));
	else if (po->map[po->p_y + 1][po->p_x] == 'C')
		collect_count(po, po->p_y + 1, po->p_x);
	else if (po->map[po->p_y + 1][po->p_x] == 'E')
		win_rule(po);
	return (1);
}

int	m_is_yn(t_game *po)
{
	if (po->map[po->p_y - 1][po->p_x] == '1')
		return (0);
	else if (po->map[po->p_y - 1][po->p_x] == 'G')
		return (game_over(po));
	else if (po->map[po->p_y - 1][po->p_x] == 'C')
		collect_count(po, po->p_y - 1, po->p_x);
	else if (po->map[po->p_y - 1][po->p_x] == 'E')
		win_rule(po);
	return (1);
}
