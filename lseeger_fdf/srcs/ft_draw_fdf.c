/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:35:33 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/25 12:45:29 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_fdf(t_fdf *fdf)
{
	t_point2d	start;
	t_point2d	end;
	int			x;
	int			y;

	y = -1;
	while (++y < fdf->map.height)
	{
		x = -1;
		while (++x < fdf->map.width)
		{
			if (x < fdf->map.width - 1)
			{
				ft_set_point2d(&start, x, y);
				ft_set_point2d(&end, x + 1, y);
				ft_connect_tiles(fdf, &start, &end);
			}
			if (y < fdf->map.height - 1)
			{
				ft_set_point2d(&start, x, y);
				ft_set_point2d(&end, x, y + 1);
				ft_connect_tiles(fdf, &start, &end);
			}
		}
	}
}
