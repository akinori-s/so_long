/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:44:28 by asasada           #+#    #+#             */
/*   Updated: 2022/11/06 23:25:33 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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
	if (ft_strchr("0CE", info->map[info->p_y + y][info->p_x + x]) != NULL)
	{
		info->map[info->p_y][info->p_x] = info->player_block;
		info->p_x += x;
		info->p_y += y;
		move_screen(info, x, y);
		info->moves += 1;
		ft_printf("%u\n", info->moves);
		if (info->map[info->p_y][info->p_x] == 'C')
		{
			info->player_block = '0';
			info->collectibles_left -= 1;
		}
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
}
