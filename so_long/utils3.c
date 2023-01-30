/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:42:45 by mbouaza           #+#    #+#             */
/*   Updated: 2023/01/30 15:14:11 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* copy my map for the second time  */

char	**copy_map_2(char **map)
{
	int		y;
	char	**copy;

	y = 0;
	copy = malloc(sizeof(char *) * (msy(map) + 1));
	if (!copy)
		return (NULL);
	while (map[y])
	{
		copy[y] = ft_strdup(map[y]);
		y++;
		if (!copy[y - 1])
			return (free_all(copy, y));
	}
	copy[y] = NULL;
	return (copy);
}

/* print end game result if you lose */

int	game_over(t_game *game)
{
	free_all(game->map, game->tabi);
	ft_printf("-------------\n");
	ft_printf("| ");
	ft_printf("\033[1;31mGame Over\033[00m");
	ft_printf(" |\n");
	ft_printf("-------------\n");
	print_stats(game);
	mlx_terminate(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}

/* print end game result if you win or exit */

int	win_game(t_game *game)
{
	free_all(game->map, game->tabi);
	if (game->exit == 1)
	{
		ft_printf("-------\n");
		ft_printf("| ");
		ft_printf("\033[1;32mWin\033[00m");
		ft_printf(" |\n");
		ft_printf("-------\n");
	}
	else
	{
		ft_printf("-------------\n");
		ft_printf("| ");
		ft_printf("\033[1;36mExit Game\033[00m");
		ft_printf(" |\n");
		ft_printf("-------------\n");
	}
	print_stats(game);
	free(game);
	exit(EXIT_SUCCESS);
}

/* print end game stats */

void	print_stats(t_game *s)
{
	ft_printf("\n----- \033[1;35mStat\033[00m -----");
	ft_printf("\n\n\033[1;32mMove\033[00m : %d", (s->move / 2) - 1);
	ft_printf("\n\n\033[1;31mBeherit\033[00m : %d", s->collect_counter);
	ft_printf("\n\n----------------\n");
}
