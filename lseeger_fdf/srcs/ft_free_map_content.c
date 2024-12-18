/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:16:11 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/22 14:54:39 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_map_content(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width)
		free(map->map[i]);
	free(map->map);
	i = -1;
	while (++i < map->width)
		free(map->color[i]);
	free(map->color);
}
