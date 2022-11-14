/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:39:28 by asasada           #+#    #+#             */
/*   Updated: 2022/11/06 23:25:24 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	get_player_pos(t_game_info *info)
{
	int	row;
	int	col;

	row = 0;
	while (info->map[row] != NULL)
	{
		col = 0;
		while (info->map[row][col] != '\0')
		{
			if (info->map[row][col] == 'P')
			{
				info->p_x = col;
				info->p_y = row;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	count_collectibles(t_game_info *info)
{
	int	row;
	int	col;

	row = 0;
	while (info->map[row] != NULL)
	{
		col = 0;
		while (info->map[row][col] != '\0')
		{
			if (info->map[row][col] == 'C')
				info->collectibles_left += 1;
			col++;
		}
		row++;
	}
}

void	get_map_info(t_game_info *info)
{
	int	row;

	row = 0;
	while (info->map[row] != NULL)
		row++;
	info->map_size_y = row;
	info->map_size_x = ft_strlen(info->map[0]);
	count_collectibles(info);
}

int	init_game_info(t_game_info *info)
{
	info->player_block = '0';
	calc_screen_settings(info);
	if (load_images(info) == -1)
	{
		ft_printf("Error\nProblem occurred while loading images.\n");
		return (-1);
	}
	return (0);
}
