/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:26:12 by asasada           #+#    #+#             */
/*   Updated: 2022/11/06 14:20:14 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	draw_game_row(t_game_info *info, int row)
{
	int	x;
	int	y;
	int	col;

	col = info->scrn_x;
	y = info->map_offset_y + ((row - info->scrn_y) * TILE_WIDTH);
	while (col < info->scrn_x_unit + info->scrn_x)
	{
		x = info->map_offset_x + ((col - info->scrn_x) * TILE_WIDTH);
		if (info->map[row][col] == '0')
			draw_empty(info, x, y);
		else if (info->map[row][col] == '1')
			draw_wall(info, x, y);
		else if (info->map[row][col] == 'C')
			draw_collectible(info, x, y);
		else if (info->map[row][col] == 'E')
			draw_exit(info, x, y);
		else if (info->map[row][col] == 'P')
			draw_player(info, x, y);
		col++;
	}
}

int	draw_game(t_game_info *info)
{
	int	row;

	row = info->scrn_y;
	while (row < info->scrn_y_unit + info->scrn_y)
	{
		draw_game_row(info, row);
		row++;
	}
	return (0);
}
