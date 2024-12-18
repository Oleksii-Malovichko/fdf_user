/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:09:17 by lseeger           #+#    #+#             */
/*   Updated: 2024/12/03 13:44:00 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	malloc_map(t_map *map)
{
	int	x;

	map->map = malloc(sizeof(int *) * map->width);
	if (!map->map)
		return (-1);
	x = -1;
	while (++x < map->width)
	{
		map->map[x] = malloc(sizeof(int) * map->height);
		if (!map->map[x])
		{
			while (--x >= 0)
				free(map->map[x]);
			free(map->map);
			return (-1);
		}
	}
	return (0);
}

static int	malloc_colors(t_map *map)
{
	int	x;

	map->color = malloc(sizeof(uint32_t *) * map->width);
	if (!map->color)
		return (-1);
	x = -1;
	while (++x < map->width)
	{
		map->color[x] = malloc(sizeof(uint32_t) * map->height);
		if (!map->color[x])
		{
			while (--x >= 0)
				free(map->color[x]);
			free(map->color);
			return (-1);
		}
	}
	return (0);
}

int	ft_init_map(t_map *map, char *file_path)
{
	if (ft_init_map_size(map, file_path) < 0)
		return (-1);
	ft_set_point2d(&map->pos, 0, 0);
	if (malloc_map(map) < 0)
		return (-1);
	if (malloc_colors(map) < 0)
	{
		ft_free_ints(map->map, map->width);
		return (-1);
	}
	return (0);
}
