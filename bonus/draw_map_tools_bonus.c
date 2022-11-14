/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_tools_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:53:46 by asasada           #+#    #+#             */
/*   Updated: 2022/11/06 21:15:10 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	draw_empty(t_game_info *info, int x, int y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->img_empty, x, y);
}

void	draw_wall(t_game_info *info, int x, int y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->img_wall, x, y);
}

void	draw_collectible(t_game_info *info, int x, int y)
{
	if (info->anim_frame_c == 0)
		mlx_put_image_to_window(info->mlx, info->win,
			info->img_collectible, x, y);
	else if (info->anim_frame_c == 1)
		mlx_put_image_to_window(info->mlx, info->win,
			info->img_collectible1, x, y);
}	

void	draw_exit(t_game_info *info, int x, int y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->img_exit, x, y);
}

void	draw_player(t_game_info *info, int x, int y)
{
	if (info->anim_frame_p == 0)
		mlx_put_image_to_window(info->mlx, info->win, info->img_player, x, y);
	else if (info->anim_frame_p == 1)
		mlx_put_image_to_window(info->mlx, info->win, info->img_player1, x, y);
	else if (info->anim_frame_p == 2)
		mlx_put_image_to_window(info->mlx, info->win, info->img_player2, x, y);
	else if (info->anim_frame_p == 3)
		mlx_put_image_to_window(info->mlx, info->win, info->img_player3, x, y);
}
