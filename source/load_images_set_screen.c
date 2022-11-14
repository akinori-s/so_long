/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_set_screen.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:42:04 by asasada           #+#    #+#             */
/*   Updated: 2022/11/03 15:50:07 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	calc_init_screen_position(t_game_info *info)
{
	info->scrn_x = info->p_x - (info->scrn_x_unit / 2);
	info->scrn_y = info->p_y - (info->scrn_y_unit / 2);
	if (info->scrn_x < 0)
		info->scrn_x = 0;
	else if (info->scrn_x > info->scrn_w_lim)
		info->scrn_x = info->scrn_w_lim;
	if (info->scrn_y < 0)
		info->scrn_y = 0;
	else if (info->scrn_y > info->scrn_h_lim)
		info->scrn_y = info->scrn_h_lim;
	if (info->map_offset_x > 0)
		info->scrn_x = 0;
	if (info->map_offset_y > 0)
		info->scrn_y = 0;
}

void	calc_screen_settings(t_game_info *info)
{
	int	mwu;
	int	mhu;
	int	tw;

	mwu = WIN_MAX_W_UNITS;
	mhu = WIN_MAX_H_UNITS;
	tw = TILE_WIDTH;
	info->scrn_x_unit = min_int(info->map_size_x, mwu);
	info->scrn_y_unit = min_int(info->map_size_y, mhu);
	info->scrn_w_lim = info->map_size_x - info->scrn_x_unit;
	info->scrn_h_lim = info->map_size_y - info->scrn_y_unit;
	if (info->scrn_x_unit < mwu)
		info->map_offset_x = (mwu - info->scrn_x_unit) * (tw / 2);
	if (info->scrn_y_unit < mhu)
		info->map_offset_y = (mhu - info->scrn_y_unit) * (tw / 2);
	calc_init_screen_position(info);
}

int	load_images(t_game_info *info)
{
	char	*path;
	int		t;

	t = TILE_WIDTH;
	path = WALL;
	info->img_wall = mlx_xpm_file_to_image(info->mlx, path, &t, &t);
	path = GROUND;
	info->img_empty = mlx_xpm_file_to_image(info->mlx, path, &t, &t);
	path = COLLECTIBLE;
	info->img_collectible = mlx_xpm_file_to_image(info->mlx, path, &t, &t);
	path = EXIT;
	info->img_exit = mlx_xpm_file_to_image(info->mlx, path, &t, &t);
	path = PLAYER;
	info->img_player = mlx_xpm_file_to_image(info->mlx, path, &t, &t);
	if (info->img_wall == NULL || info->img_empty == NULL || \
		info->img_collectible == NULL || \
		info->img_exit == NULL || info->img_player == NULL)
		return (-1);
	return (0);
}
