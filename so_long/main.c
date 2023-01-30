/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:28:58 by mbouaza           #+#    #+#             */
/*   Updated: 2023/01/30 14:59:04 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* initialize my variables to 0 */

void	struct_initialisation(t_game *var, char *str)
{
	var->map = copy_map(str, var);
	var->c = 0;
	var->p = 0;
	var->e = 0;
	var->x = 0;
	var->y = 0;
	var->move = 1;
	var->random = 0;
	var->p_o = 0;
	var->p_x = 0;
	var->p_y = 0;
	var->collect_counter = 0;
	var->portail = 0;
	var->i = 0;
}

/* to control my character */

void	key(mlx_key_data_t keydata, void *param)
{
	t_game	*run;

	run = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		win_game(run);
	if (mlx_is_key_down(run->mlx, MLX_KEY_A) && m_is_xn(run))
		move_neg_x(run);
	else if (mlx_is_key_down(run->mlx, MLX_KEY_D) && m_is_xp(run))
		move_pos_x(run);
	else if (mlx_is_key_down(run->mlx, MLX_KEY_W) && m_is_yn(run))
		move_neg_y(run);
	else if (mlx_is_key_down(run->mlx, MLX_KEY_S) && m_is_yp(run))
		move_pos_y(run);
}

/* main */

int32_t	main(int argc, char **argv)
{
	t_game	*run;

	if (argc != 2 || !check_ber(argv[1]))
	{
		ft_printf("Error\n• Usage: ./so_long [map.ber]\n");
		exit(EXIT_FAILURE);
	}
	run = malloc(sizeof(t_game));
	if (!run)
		exit(EXIT_FAILURE);
	struct_initialisation(run, argv[1]);
	if (!check_all(run->map, run))
		exit (EXIT_FAILURE);
	run->mlx = mlx_init(msx(run->map) * S, msy(run->map) * S, "Berserk", true);
	if (!run->mlx)
		exit(EXIT_FAILURE);
	create_map(run, run->map);
	mlx_loop_hook(run->mlx, &portal, run);
	character_init(run, run->map);
	mlx_key_hook(run->mlx, key, run);
	mlx_loop(run->mlx);
	mlx_terminate(run->mlx);
	return (win_game(run));
}
