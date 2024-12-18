/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:34:24 by lseeger           #+#    #+#             */
/*   Updated: 2024/12/09 14:33:03 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_isometric(t_point3d *point, t_point2d *pixel_pos)
{ 
	pixel_pos->x = (point->x - point->y) * cos(M_PI / 6);
	pixel_pos->y = (point->x + point->y) * sin(M_PI / 6) - point->z;
}

void	ft_get_parallel(t_point3d *point, t_point2d *pixel_pos)
{
	pixel_pos->x = point->x;
	pixel_pos->y = point->y - point->z;
}

// epsilon is used to prevent division by zero
void	ft_get_perspective(t_point3d *point, t_point2d *pixel_pos)
{
	double			z;
	const double	epsilon = 0.0001;

	z = 1 + point->z / 100.0;
	if (fabs(z) < epsilon)
		z = epsilon;
	pixel_pos->x = point->x / z;
	pixel_pos->y = point->y / z;
}

void	ft_get_orthographic(t_point3d *point, t_point2d *pixel_pos)
{
	pixel_pos->x = point->x;
	pixel_pos->y = point->y;
}
