/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cli_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:30:30 by asasada           #+#    #+#             */
/*   Updated: 2022/11/06 13:06:44 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_map_extension(char **fp_arr)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (fp_arr[i] != NULL)
		i++;
	if (i > 0)
		i--;
	if (fp_arr[i] == NULL)
	{
		free_map(fp_arr);
		return (-1);
	}
	if (ft_strlen(fp_arr[i]) <= 4)
		ret = -1;
	else if (ft_strncmp(fp_arr[i] + ft_strlen(fp_arr[i]) - 4, ".ber", 4) != 0)
		ret = -1;
	free_map(fp_arr);
	return (ret);
}

int	check_file_name(char *map_file_path)
{
	size_t	file_path_len;
	char	**fp_arr;

	file_path_len = ft_strlen(map_file_path);
	if (file_path_len <= 4)
	{
		ft_printf("Error\nInvalid file name.\n");
		return (-1);
	}
	fp_arr = ft_split(map_file_path, '/');
	if (fp_arr == NULL)
	{
		ft_printf("Error\nProblem occurred while validating file path.\n");
		return (-1);
	}
	if (check_map_extension(fp_arr) == -1)
	{
		ft_printf("Error\nInvalid extension for map file.\n");
		return (-1);
	}
	return (0);
}

int	read_map(t_game_info *info, int fd)
{
	char	*next_line;
	char	*tmp;

	next_line = get_next_line(fd);
	while (next_line != NULL)
	{
		tmp = info->map_flattened;
		info->map_flattened = ft_strjoin(info->map_flattened, next_line);
		free(tmp);
		free(next_line);
		if (info->map_flattened == NULL)
			return (-1);
		next_line = get_next_line(fd);
	}
	info->map = ft_split(info->map_flattened, '\n');
	info->map_pc = ft_split(info->map_flattened, '\n');
	free(info->map_flattened);
	info->map_flattened = NULL;
	if (info->map == NULL || info->map_pc == NULL)
	{
		free_map(info->map);
		free_map(info->map_pc);
		return (-1);
	}
	return (0);
}

int	check_cli_args(t_game_info *info, int argc, char *argv[])
{
	int		fd;
	int		ret;

	if (argc != 2)
	{
		ft_printf("Error\nIncorrect number of  arguments.\n");
		return (-1);
	}
	if (check_file_name(argv[1]) == -1)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n%s\n", strerror(errno));
		return (-1);
	}
	ret = read_map(info, fd);
	close(fd);
	if (ret == -1)
	{
		ft_printf("Error\nProblem occurred while reading the map.\n");
		return (-1);
	}
	return (0);
}
