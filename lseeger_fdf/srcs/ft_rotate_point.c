/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:43:09 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/27 13:51:40 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	y_rotation(t_point3d *point, t_point3d_d *cos_rotation,
		t_point3d_d *sin_rotation)
{
	double	rotated_x;
	double	rotated_z;

	rotated_x = cos_rotation->y * point->x - sin_rotation->y * point->z;
	rotated_z = sin_rotation->y * point->x + cos_rotation->y * point->z;
	point->x = rotated_x;
	point->z = rotated_z;
}

static void	x_rotation(t_point3d *point, t_point3d_d *cos_rotation,
		t_point3d_d *sin_rotation)
{
	double	rotated_y;
	double	rotated_z;

	rotated_y = cos_rotation->x * point->y - sin_rotation->x * point->z;
	rotated_z = sin_rotation->x * point->y + cos_rotation->x * point->z;
	point->y = rotated_y;
	point->z = rotated_z;
}

static void	z_rotation(t_point3d *point, t_point3d_d *cos_rotation,
		t_point3d_d *sin_rotation)
{
	double	rotated_x;
	double	rotated_y;

	rotated_x = cos_rotation->z * point->x - sin_rotation->z * point->y;
	rotated_y = sin_rotation->z * point->x + cos_rotation->z * point->y;
	point->x = rotated_x;
	point->y = rotated_y;
}

void	ft_rotate_point(t_point3d *point, t_point3d_d *viewport)
{
	t_point3d_d	cos_rotation;
	t_point3d_d	sin_rotation;

	ft_set_point3d_d(&cos_rotation, cos(viewport->x), cos(viewport->y),
		cos(viewport->z));
	ft_set_point3d_d(&sin_rotation, sin(viewport->x), sin(viewport->y),
		sin(viewport->z));
	y_rotation(point, &cos_rotation, &sin_rotation);
	x_rotation(point, &cos_rotation, &sin_rotation);
	z_rotation(point, &cos_rotation, &sin_rotation);
}
