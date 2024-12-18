/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:13:11 by lseeger           #+#    #+#             */
/*   Updated: 2024/12/02 16:23:29 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	count_nls(char *buffer, ssize_t bytes_read, bool *nl_found)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
			*nl_found = true;
		else if (buffer[i] != '\n' && *nl_found)
		{
			count++;
			*nl_found = false;
		}
		i++;
	}
	return (count);
}

int	ft_get_line_count(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		count;
	ssize_t	bytes_read;
	bool	nl_found;

	nl_found = true;
	count = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		count += count_nls(buffer, bytes_read, &nl_found);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (-1);
	return (count);
}
