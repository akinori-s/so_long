/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:53:27 by asasada           #+#    #+#             */
/*   Updated: 2022/11/06 15:28:55 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	check_node(t_game_info *info, int x, int y)
{
	t_list	*t;
	t_xy	*coord;

	if (info->map_pc[y][x] == '1')
		return (0);
	else if (info->map_pc[y][x] == 'C')
		info->collectibles_reachable += 1;
	else if (info->map_pc[y][x] == 'E')
		info->exit_reachable = true;
	coord = (t_xy *)malloc(sizeof(t_xy));
	if (coord == NULL)
		return (-1);
	coord->x = x;
	coord->y = y;
	t = ft_lstnew(coord);
	if (t == NULL)
	{
		free(coord);
		coord = NULL;
		return (-1);
	}
	ft_lstadd_back(info->lst, t);
	info->map_pc[y][x] = '1';
	return (0);
}

int	check_four_directions(t_game_info *info, t_list *node)
{
	int	x;
	int	y;
	int	ret;

	ret = 0;
	x = ((t_xy *)node->content)->x;
	y = ((t_xy *)node->content)->y;
	info->map_pc[y][x] = '1';
	ret += check_node(info, x - 1, y);
	ret += check_node(info, x, y - 1);
	ret += check_node(info, x + 1, y);
	ret += check_node(info, x, y + 1);
	return (ret);
}

int	check_valid_path_loop(t_game_info *info)
{
	while (*info->lst != NULL)
	{
		if (check_four_directions(info, *info->lst) < 0)
		{
			ft_lstdelall(info->lst);
			return (-1);
		}
		ft_lstdelfirst(info->lst);
		if (info->collectibles_left == info->collectibles_reachable && \
			info->exit_reachable)
		{
			ft_lstdelall(info->lst);
			return (0);
		}
	}
	return (-1);
}

int	check_map_valid_path(t_game_info *info)
{
	t_list	*t;
	t_xy	*coord;

	coord = (t_xy *)malloc(sizeof(t_xy));
	if (coord == NULL)
		return (-1);
	coord->x = info->p_x;
	coord->y = info->p_y;
	t = ft_lstnew(coord);
	if (t == NULL)
	{
		free(coord);
		return (-1);
	}
	info->lst = &t;
	return (check_valid_path_loop(info));
}
