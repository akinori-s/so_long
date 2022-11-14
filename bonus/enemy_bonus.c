/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:59:36 by asasada           #+#    #+#             */
/*   Updated: 2022/11/07 23:19:34 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	lose_game(t_game_info *info)
{
	ft_printf("You lost!\n");
	destroy_game(info, 0);
}

void	place_enemy(t_game_info *info)
{
	int	row;
	int	col;

	info->e_exists = false;
	row = 0;
	while (info->map[row] != NULL)
	{
		col = 0;
		while (info->map[row][col] != '\0')
		{
			if (info->map[row][col] == '0')
			{
				info->map[row][col] = 'X';
				info->e_x = col;
				info->e_y = row;
				info->e_block = '0';
				info->e_exists = true;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	move_enemy(t_game_info *info, int x, int y)
{
	if (info->map[info->e_y + y][info->e_x + x] == '1')
		return ;
	if (info->map[info->e_y + y][info->e_x + x] == 'P')
		lose_game(info);
	info->map[info->e_y][info->e_x] = info->e_block;
	info->e_x += x;
	info->e_y += y;
	info->e_block = info->map[info->e_y][info->e_x];
	info->map[info->e_y][info->e_x] = 'X';
}

void	enemy_hook(t_game_info *info)
{
	int	move;

	move = (info->p_x + info->p_y) % 4;
	if (move == 0)
		move_enemy(info, -1, 0);
	if (move == 1)
		move_enemy(info, 0, -1);
	if (move == 2)
		move_enemy(info, 1, 0);
	if (move == 3)
		move_enemy(info, 0, 1);
}

void	draw_enemy(t_game_info *info, int x, int y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->img_enemy, x, y);
}
