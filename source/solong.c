/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:18:17 by asasada           #+#    #+#             */
/*   Updated: 2022/11/06 13:44:00 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	key_hook(int keycode, t_game_info *info)
{
	if (keycode == XK_ESC)
		destroy_game(info, 0);
	else if (keycode == XK_W)
		move_player(info, 0, -1);
	else if (keycode == XK_A)
		move_player(info, -1, 0);
	else if (keycode == XK_D)
		move_player(info, 1, 0);
	else if (keycode == XK_S)
		move_player(info, 0, 1);
	else
		return (0);
	draw_game(info);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game_info	info;

	info = (t_game_info){0};
	if (check_cli_args(&info, argc, argv) == -1)
		exit(-1);
	if (check_map_format(&info) == -1)
		destroy_game(&info, -1);
	info.mlx = mlx_init();
	if (info.mlx == NULL)
		destroy_game(&info, -1);
	info.win = mlx_new_window(info.mlx, WIN_MAX_WIDTH, WIN_MAX_HEIGHT, WNAME);
	if (info.win == NULL)
		destroy_game(&info, -1);
	if (init_game_info(&info) == -1)
		destroy_game(&info, -1);
	draw_game(&info);
	mlx_hook(info.win, KeyPress, KeyPressMask, key_hook, &info);
	mlx_hook(info.win, DestroyNotify, StructureNotifyMask, x_button, &info);
	mlx_hook(info.win, Expose, ExposureMask, draw_game, &info);
	mlx_loop(info.mlx);
	return (0);
}
