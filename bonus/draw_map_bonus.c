/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:53:38 by asasada           #+#    #+#             */
/*   Updated: 2022/11/09 20:51:40 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int		count_uint_digits_in_base(unsigned int n, int base);
char	*uint_to_str(unsigned int n, int base);

int	anim_counter(t_game_info *info)
{
	info->anim_counter_p += 1;
	info->anim_counter_c += 1;
	if (info->anim_counter_p >= 20000)
	{
		info->anim_counter_p = 0;
		info->anim_frame_p += 1;
		if (info->anim_frame_p >= 4)
			info->anim_frame_p = 0;
		info->draw_anim = true;
		draw_game(info);
	}
	if (info->anim_counter_c >= 23000)
	{
		info->anim_counter_c = 0;
		info->anim_frame_c += 1;
		if (info->anim_frame_c >= 2)
			info->anim_frame_c = 0;
		if (info->e_exists)
			enemy_hook(info);
		info->draw_anim = true;
		draw_game(info);
	}
	return (0);
}

void	draw_moves(t_game_info *info, int x, int y, int c)
{
	char	*str;

	str = uint_to_str(info->moves, 10);
	if (str == NULL)
		return ;
	if (info->map_s[0][0] == '0')
		draw_empty(info, info->map_offset_x, info->map_offset_y);
	else if (info->map_s[0][0] == '1')
		draw_wall(info, info->map_offset_x, info->map_offset_y);
	else if (info->map_s[0][0] == 'C')
		draw_collectible(info, info->map_offset_x, info->map_offset_y);
	else if (info->map_s[0][0] == 'E')
		draw_exit(info, info->map_offset_x, info->map_offset_y);
	else if (info->map_s[0][0] == 'P')
		draw_player(info, info->map_offset_x, info->map_offset_y);
	else if (info->map_s[0][0] == 'X')
		draw_enemy(info, info->map_offset_x, info->map_offset_y);
	mlx_string_put(info->mlx, info->win, x + info->map_offset_x,
		y + info->map_offset_y, c, str);
	free(str);
	str = NULL;
}

void	draw_game_row(t_game_info *i, int row, int r_s, int y)
{
	int	x;
	int	col;

	col = i->scrn_x;
	while (col < i->scrn_x_unit + i->scrn_x)
	{
		if (i->map_s[r_s][col - i->scrn_x] != i->map[row][col] || i->first_draw)
		{
			i->map_s[r_s][col - i->scrn_x] = i->map[row][col];
			x = i->map_offset_x + ((col - i->scrn_x) * TILE_WIDTH);
			if (i->map[row][col] == '0')
				draw_empty(i, x, y);
			else if (i->map[row][col] == '1')
				draw_wall(i, x, y);
			else if (i->map[row][col] == 'C')
				draw_collectible(i, x, y);
			else if (i->map[row][col] == 'E')
				draw_exit(i, x, y);
			else if (i->map[row][col] == 'P')
				draw_player(i, x, y);
			else if (i->map[row][col] == 'X')
				draw_enemy(i, x, y);
		}
		col++;
	}
}

void	draw_anim_row(t_game_info *info, int row, int y)
{
	int	x;
	int	col;

	col = info->scrn_x;
	while (col < info->scrn_x_unit + info->scrn_x)
	{
		x = info->map_offset_x + ((col - info->scrn_x) * TILE_WIDTH);
		if (info->map[row][col] == 'C')
			draw_collectible(info, x, y);
		else if (info->map[row][col] == 'P')
			draw_player(info, x, y);
		col++;
	}
}

int	draw_game(t_game_info *info)
{
	int	row;
	int	y;

	row = info->scrn_y;
	while (row < info->scrn_y_unit + info->scrn_y)
	{
		y = info->map_offset_y + ((row - info->scrn_y) * TILE_WIDTH);
		draw_game_row(info, row, row - info->scrn_y, y);
		if (info->draw_anim)
			draw_anim_row(info, row, y);
		row++;
	}
	info->first_draw = false;
	info->draw_anim = false;
	draw_moves(info, 17, 25, 16777215);
	return (0);
}
