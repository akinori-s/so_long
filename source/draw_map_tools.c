/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:26:10 by asasada           #+#    #+#             */
/*   Updated: 2022/11/06 14:19:40 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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
	mlx_put_image_to_window(info->mlx, info->win, info->img_collectible, x, y);
}

void	draw_exit(t_game_info *info, int x, int y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->img_exit, x, y);
}

void	draw_player(t_game_info *info, int x, int y)
{
	mlx_put_image_to_window(info->mlx, info->win, info->img_player, x, y);
}
