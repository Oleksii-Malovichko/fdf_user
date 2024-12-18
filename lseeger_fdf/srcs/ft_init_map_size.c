/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:11:13 by lseeger           #+#    #+#             */
/*   Updated: 2024/12/03 14:26:39 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	ft_get_map_width(int fd)
{
	char	*first_line;
	int		i;
	int		count;
	bool	space_found;

	first_line = get_next_line(fd);
	count = 0;
	i = 0;
	space_found = true;
	while (first_line[i])
	{
		if (first_line[i] == ' ' || first_line[i] == '\n')
			space_found = true;
		else if (space_found)
		{
			count++;
			space_found = false;
		}
		i++;
	}
	return (free(first_line), count);
}

int	ft_init_map_size(t_map *map, char *file_name)
{
	int		fd;
	char	*buffer;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	map->height = ft_get_line_count(fd);
	close(fd);
	if (map->height < 0)
		return (-1);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	map->width = ft_get_map_width(fd);
	buffer = get_buffer(fd);
	buffer[0] = 0;
	close(fd);
	if (map->width < 0)
		return (-1);
	else
		return (0);
}
