/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:12:57 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/26 16:28:44 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_point2d(t_point2d *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

void	ft_set_point3d(t_point3d *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

void	ft_set_point3d_d(t_point3d_d *point, double x, double y, double z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}
