/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:50:16 by mbouaza           #+#    #+#             */
/*   Updated: 2023/01/30 15:14:26 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ------ Macro ------ */

# define S 64

/* ------ Include ------ */

# include "MLX42/include/MLX42/MLX42.h"
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

/* ------ Struct ------ */

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*guts;
	mlx_image_t		*put;
	mlx_image_t		*portail;
	mlx_image_t		*b;
	int				*num;
	char			**map;
	int				c;
	int				p;
	int				e;
	int				x;
	int				y;
	int				tabi;
	int				p_o;
	int				collect_counter;
	int				move;
	int				random;
	int				p_x;
	int				p_y;
	int				i;
	int				exit;
}				t_game;

/* ------ function ------ */

// main //

int32_t	main(int argc, char **argv);
void	struct_initialisation(t_game *var, char *str);
void	key(mlx_key_data_t keydata, void *param);

// utils //

int		error_message(int num_of_error);
int		check_char(char word, char c);
char	*ft_strdup(const char *s1);
char	**free_all(char **map, int i);
char	*ft_s(char const *s1, char const *s2);

// utils2 //

int		find_p_x(char **map, char c);
int		find_p_y(char **map, char c);
void	print_count(t_game *counter, int number);
char	*ft_itoa(int nbr);

// utils3 //

char	**copy_map_2(char **map);
int		game_over(t_game *game);
int		win_game(t_game *game);
void	print_stats(t_game *s);

// texture //

void	render_sprite(t_game *sprit, int x, int y, char *path);
void	render_sprite_light(t_game *sprit, int x, int y, char *path);
void	create_map(t_game *sprit, char **map);
// void 	beherit(t_game *cb, mlx_texture_t *t, int x, int y, int i);

// map //

int		msx(char **map);
int		msy(char **map);
int		count_map(char *file, t_game *c);
char	**copy_map(char *file, t_game *c);
void	collect_count(t_game *collect, int y, int x);

// check_map //

int		check_all(char **map, t_game *item);
int		check_body(char **map);
int		check_wall(char **map);
int		check_ber(char *file);
int		check_double(t_game *item, char **map);

// check_map2 //

int		*search_is_p(char **map, int x, int y, char c);
int		check_is_possible(t_game *check);
int		count_c(char **map);
int		test_item(char c);
int		check_has_more(char **map);

// key //

void	character_init(t_game *sprit, char **map);
void	move_pos_x(t_game *run);
void	move_neg_x(t_game *run);
void	move_pos_y(t_game *run);
void	move_neg_y(t_game *run);

// gameset.c //

int		m_is_xp(t_game *po);
int		m_is_xn(t_game *po);
int		m_is_yp(t_game *po);
int		m_is_yn(t_game *po);

// animation //s

void	portal(void *param);
// void	anim_beherit(void *param);
void	character_init2(t_game *sprit, char **map);
int		win_rule(t_game *win);

#endif
