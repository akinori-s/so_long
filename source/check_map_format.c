/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:32:54 by asasada           #+#    #+#             */
/*   Updated: 2022/11/06 14:40:39 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_map_rectangularity(t_game_info *info)
{
	int		row;
	size_t	base_col_len;

	row = 0;
	base_col_len = ft_strlen(info->map[0]);
	while (info->map[row] != NULL)
	{
		if (ft_strlen(info->map[row]) != base_col_len)
			return (-1);
		row++;
	}
	return (0);
}

int	check_wall_enclosure(t_game_info *info)
{
	size_t	col;
	size_t	row;
	size_t	i;

	col = ft_strlen(info->map[0]);
	row = 0;
	while (info->map[row] != NULL)
	{
		if (info->map[row][0] != '1' || info->map[row][col - 1] != '1')
			return (-1);
		row++;
	}
	i = 0;
	while (i < col)
	{
		if (info->map[0][i] != '1' || info->map[row - 1][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_map_char_count(t_game_info *info)
{
	size_t				row;
	size_t				col;
	static size_t		counts[3];

	row = 0;
	while (info->map[row] != NULL)
	{
		col = 0;
		while (info->map[row][col] != '\0')
		{
			if (info->map[row][col] == 'P')
				counts[0]++;
			else if (info->map[row][col] == 'C')
				counts[1]++;
			else if (info->map[row][col] == 'E')
				counts[2]++;
			col++;
		}
		row++;
	}
	if (counts[0] != 1 || counts[1] <= 0 || counts[2] != 1)
		return (-1);
	return (0);
}

int	check_map_chars(t_game_info *info)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (info->map[row] != NULL)
	{
		col = 0;
		while (info->map[row][col] != '\0')
		{
			if (ft_strchr("01PCE", info->map[row][col]) == NULL)
				return (-1);
			col++;
		}
		row++;
	}
	if (check_map_char_count(info) == -1)
		return (-1);
	return (0);
}

int	check_map_format(t_game_info *info)
{
	if (check_map_rectangularity(info) == -1)
	{
		ft_printf("Error\nThe map is not rectangular.\n");
		return (-1);
	}
	else if (check_wall_enclosure(info) == -1)
	{
		ft_printf("Error\nThe map is not enclosed by walls.\n");
		return (-1);
	}
	else if (check_map_chars(info) == -1)
	{
		ft_printf("Error\nThe map contains an invalid character or it doesn't \
		have the right number of players, collectibles or exits.\n");
		return (-1);
	}
	get_player_pos(info);
	get_map_info(info);
	if (check_map_valid_path(info) == -1)
	{
		ft_printf("Error\nThe map does not contain a valid path.\n");
		return (-1);
	}
	return (0);
}
