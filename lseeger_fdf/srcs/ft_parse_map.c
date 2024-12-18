/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:51:55 by lseeger           #+#    #+#             */
/*   Updated: 2024/12/04 13:05:12 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	parse_pair(t_map *map, char **pairs)
{
	char	**split;

	if (map->pos.x >= map->width || map->pos.y >= map->height)
		return (0);
	split = ft_split(pairs[map->pos.x], ',');
	if (!split)
		return (ft_printf("Failed to Split Pair: %s\n", pairs[map->pos.x]) - 1);
	map->map[map->pos.x][map->pos.y] = ft_atoi(split[0]);
	ft_remove_c(split[1], "\n");
	if (ft_aish(split[1]))
		map->color[map->pos.x][map->pos.y] = ft_atocolor(split[1]);
	else
		map->color[map->pos.x][map->pos.y] = DEFAULT_COLOR;
	ft_free_strs(split);
	return (0);
}

static int	ft_parse_line(t_map *map, char *line)
{
	char	**pairs;

	pairs = ft_split(line, ' ');
	if (!pairs)
		return (ft_printf("Failed to split line: %s\n", line), -1);
	map->pos.x = 0;
	while (pairs[map->pos.x])
	{
		if (parse_pair(map, pairs) < 0)
			return (ft_free_strs(pairs), -1);
		map->pos.x++;
	}
	ft_free_strs(pairs);
	return (0);
}

int	ft_parse_map(t_map *map, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Failed to Open File\n"), -1);
	line = get_next_line(fd);
	if (!line)
		return (ft_printf("Failed to get first line\n"), close(fd), -1);
	map->pos.y = 0;
	while (line)
	{
		if (ft_parse_line(map, line) < 0)
			return (free(line), close(fd), -1);
		free(line);
		line = get_next_line(fd);
		map->pos.y++;
	}
	return (close(fd), 0);
}
