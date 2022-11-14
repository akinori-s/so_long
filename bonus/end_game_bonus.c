/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:53:52 by asasada           #+#    #+#             */
/*   Updated: 2022/11/09 08:41:33 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	free_map(char **map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	destroy_bonus_images(t_game_info *info)
{
	if (info->mlx != NULL && info->img_collectible1 != NULL)
		mlx_destroy_image(info->mlx, info->img_collectible1);
	if (info->mlx != NULL && info->img_player1 != NULL)
		mlx_destroy_image(info->mlx, info->img_player1);
	if (info->mlx != NULL && info->img_player2 != NULL)
		mlx_destroy_image(info->mlx, info->img_player2);
	if (info->mlx != NULL && info->img_player3 != NULL)
		mlx_destroy_image(info->mlx, info->img_player3);
	if (info->mlx != NULL && info->img_enemy != NULL)
		mlx_destroy_image(info->mlx, info->img_enemy);
}

void	destroy_game(t_game_info *info, int status)
{
	free_map(info->map);
	free_map(info->map_pc);
	free_map(info->map_s);
	destroy_bonus_images(info);
	if (info->mlx != NULL && info->img_wall != NULL)
		mlx_destroy_image(info->mlx, info->img_wall);
	if (info->mlx != NULL && info->img_empty != NULL)
		mlx_destroy_image(info->mlx, info->img_empty);
	if (info->mlx != NULL && info->img_collectible != NULL)
		mlx_destroy_image(info->mlx, info->img_collectible);
	if (info->mlx != NULL && info->img_exit != NULL)
		mlx_destroy_image(info->mlx, info->img_exit);
	if (info->mlx != NULL && info->img_player != NULL)
		mlx_destroy_image(info->mlx, info->img_player);
	if (info->mlx != NULL && info->win != NULL)
		mlx_destroy_window(info->mlx, info->win);
	if (info->mlx != NULL)
		mlx_destroy_display(info->mlx);
	free(info->mlx);
	info->mlx = NULL;
	exit(status);
}

void	end_game(t_game_info *info)
{
	ft_printf("Game Won!\n");
	destroy_game(info, 0);
}

int	x_button(t_game_info *info)
{
	destroy_game(info, 0);
	return (0);
}
