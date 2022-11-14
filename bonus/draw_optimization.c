/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_optimization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:15:15 by asasada           #+#    #+#             */
/*   Updated: 2022/11/09 21:18:06 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	make_screen_map(t_game_info *info)
{
	int		row;
	int		y;
	char	*tmp;

	info->map_s = (char **)malloc((info->scrn_y_unit + 1) * sizeof(char *));
	if (info->map_s == NULL)
		return (-1);
	row = 0;
	while (row < info->scrn_y_unit + 1)
		info->map_s[row++] = NULL;
	row = 0;
	while (row < info->scrn_y_unit)
	{
		y = info->scrn_y + row;
		tmp = ft_substr(info->map[y], info->scrn_x, info->scrn_x_unit);
		info->map_s[row] = tmp;
		if (info->map_s[row] == NULL)
		{
			free_map(info->map_s);
			return (-1);
		}
		row++;
	}
	return (0);
}

int	draw_expose(t_game_info *info)
{
	info->first_draw = true;
	draw_game(info);
	return (0);
}
