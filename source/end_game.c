/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:50:38 by asasada           #+#    #+#             */
/*   Updated: 2022/11/06 14:23:04 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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

void	destroy_game(t_game_info *info, int status)
{
	free_map(info->map);
	free_map(info->map_pc);
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

int	end_game(t_game_info *info)
{
	ft_printf("Game Won!\n");
	destroy_game(info, 0);
	return (0);
}

int	x_button(t_game_info *info)
{
	destroy_game(info, 0);
	return (0);
}
