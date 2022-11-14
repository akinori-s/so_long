/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:56:01 by asasada           #+#    #+#             */
/*   Updated: 2022/11/09 21:18:25 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_BONUS_H
# define SOLONG_BONUS_H

# include "solong_bonus.h"
# include "libft.h"
# include "ft_printf.h"
# include "math_utils_bonus.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include <X.h>
# include <mlx.h>
# include <keysymdef.h>

typedef struct s_game_info {
	void	*mlx;
	void	*win;
	size_t	moves;

	char	**map;
	char	**map_pc;
	char	**map_s;
	char	*map_flattened;

	int		p_x;
	int		p_y;
	char	player_block;
	size_t	collectibles_left;

	int		scrn_x;
	int		scrn_y;

	int		map_size_x;
	int		map_size_y;

	int		map_offset_x;
	int		map_offset_y;

	int		scrn_x_unit;
	int		scrn_y_unit;

	int		scrn_w_lim;
	int		scrn_h_lim;

	void	*img_wall;
	void	*img_empty;
	void	*img_collectible;
	void	*img_exit;
	void	*img_player;

	t_list	**lst;
	bool	exit_reachable;
	size_t	collectibles_reachable;

	void	*img_player1;
	void	*img_player2;
	void	*img_player3;
	void	*img_collectible1;
	void	*img_enemy;

	int		anim_counter_p;
	int		anim_counter_c;
	int		anim_frame_p;
	int		anim_frame_c;

	bool	e_exists;
	bool	first_draw;
	bool	draw_anim;
	int		e_x;
	int		e_y;
	char	e_block;
}	t_game_info;

typedef struct s_xy {
	int	x;
	int	y;
}	t_xy;

# define WNAME "Money printer go brrr!"

# define XK_ESC 65307
# define XK_Q 113
# define XK_W 119
# define XK_A 97
# define XK_S 115
# define XK_D 100

# define TILE_WIDTH 40
# define WIN_MAX_WIDTH 1280
# define WIN_MAX_HEIGHT 720
# define WIN_MAX_W_UNITS 32
# define WIN_MAX_H_UNITS 18

# define WALL "./assets/wall.xpm"
# define PLAYER "./assets/player.xpm"
# define GROUND "./assets/ground.xpm"
# define EXIT "./assets/exit.xpm"
# define COLLECTIBLE "./assets/collectible.xpm"

# define PLAYER1 "./assets/player_1.xpm"
# define PLAYER2 "./assets/player_2.xpm"
# define PLAYER3 "./assets/player_3.xpm"
# define COLLECTIBLE1 "./assets/collectible_1.xpm"
# define ENEMY "./assets/enemy.xpm"

// draw_map
int		anim_counter(t_game_info *info);
void	draw_moves(t_game_info *info, int x, int y, int c);
void	draw_game_row(t_game_info *i, int row, int r_s, int y);
void	draw_anim_row(t_game_info *info, int row, int y);
int		draw_game(t_game_info *info);

// draw_map_tools
void	draw_empty(t_game_info *info, int x, int y);
void	draw_wall(t_game_info *info, int x, int y);
void	draw_collectible(t_game_info *info, int x, int y);
void	draw_exit(t_game_info *info, int x, int y);
void	draw_player(t_game_info *info, int x, int y);

// check_cli_args
int		check_map_extension(char **fp_arr);
int		check_file_name(char *map_file_path);
int		read_map(t_game_info *info, int fd);
int		check_cli_args(t_game_info *info, int argc, char *argv[]);

// check_map_format
int		check_map_rectangularity(t_game_info *info);
int		check_wall_enclosure(t_game_info *info);
int		check_map_char_count(t_game_info *info);
int		check_map_chars(t_game_info *info);
int		check_map_format(t_game_info *info);

// list_utils
void	ft_lstdelall(t_list **lst);
void	ft_lstdelfirst(t_list **lst);

// check_valid_path
int		check_node(t_game_info *info, int x, int y);
int		check_four_directions(t_game_info *info, t_list *node);
int		check_valid_path_loop(t_game_info *info);
int		check_map_valid_path(t_game_info *info);

// init_game_info
void	get_player_pos(t_game_info *info);
void	count_collectibles(t_game_info *info);
void	get_map_info(t_game_info *info);
int		init_game_info(t_game_info *info);

// load_images_set_screen
void	calc_init_screen_position(t_game_info *info);
void	calc_screen_settings(t_game_info *info);
int		load_bonus_images(t_game_info *info);
int		load_images(t_game_info *info);

// player_movement
void	move_screen(t_game_info *info, int x, int y);
void	move_player(t_game_info *info, int x, int y);

// end_game
void	free_map(char **map);
void	destroy_bonus_images(t_game_info *info);
void	destroy_game(t_game_info *info, int status);
void	end_game(t_game_info *info);
int		x_button(t_game_info *info);

// enemy_bonus
void	lose_game(t_game_info *info);
void	place_enemy(t_game_info *info);
void	move_enemy(t_game_info *info, int x, int y);
void	enemy_hook(t_game_info *info);
void	draw_enemy(t_game_info *info, int x, int y);

// draw_optimization
int		make_screen_map(t_game_info *info);
int		draw_expose(t_game_info *info);

#endif