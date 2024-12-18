/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:17:28 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/21 12:35:50 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_heigth_map(t_map *map)
{
	int	x;
	int	y;

	write(1, "\theigth map\n\t\t", 14);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			ft_printf("%d ", map->map[x][y]);
		write(1, "\n", 1);
		if (y < map->height - 1)
			write(1, "\t\t", 2);
	}
}

static void	print_color_map(t_map *map)
{
	int	x;
	int	y;

	write(1, "\tcolor map\n\t\t", 13);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			ft_printf("%u ", map->color[x][y]);
		write(1, "\n", 1);
		if (y < map->height - 1)
			write(1, "\t\t", 2);
	}
}

void	ft_print_map(t_map *map, bool print_map, bool print_color)
{
	ft_printf("print_map\n");
	ft_printf("\twidth: %d\n", map->width);
	ft_printf("\theight: %d\n", map->height);
	if (print_map)
		print_heigth_map(map);
	if (print_color)
		print_color_map(map);
}
