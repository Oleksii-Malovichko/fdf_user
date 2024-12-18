/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:46:59 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/27 14:49:30 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_scale_point2d(t_point2d *point, float scale)
{
	point->x *= scale;
	point->y *= scale;
}

void	ft_scale_point3d(t_point3d *point, float scale)
{
	point->x *= scale;
	point->y *= scale;
	point->z *= scale;
}
