/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:54:16 by asasada           #+#    #+#             */
/*   Updated: 2022/11/07 22:19:51 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	move_screen(t_game_info *info, int x, int y)
{
	if (info->scrn_x + x >= 0 && info->scrn_x + x <= info->scrn_w_lim \
		&& !((info->p_x * x) < (info->scrn_x + (info->scrn_x_unit / 2)) * x))
		info->scrn_x += x;
	if (info->scrn_y + y >= 0 && info->scrn_y + y <= info->scrn_h_lim \
		&& !((info->p_y * y) < (info->scrn_y + (info->scrn_y_unit / 2)) * y))
		info->scrn_y += y;
}

void	move_player(t_game_info *info, int x, int y)
{
	if (info->map[info->p_y + y][info->p_x + x] == '1')
		return ;
	info->map[info->p_y][info->p_x] = info->player_block;
	info->p_x += x;
	info->p_y += y;
	move_screen(info, x, y);
	info->moves += 1;
	if (info->map[info->p_y][info->p_x] == 'C')
	{
		info->player_block = '0';
		info->collectibles_left -= 1;
	}
	else if (info->map[info->p_y][info->p_x] == 'X')
		lose_game(info);
	else if (info->map[info->p_y][info->p_x] == 'E')
	{
		info->player_block = 'E';
		if (info->collectibles_left == 0)
			end_game(info);
	}
	else
		info->player_block = '0';
	info->map[info->p_y][info->p_x] = 'P';
}
