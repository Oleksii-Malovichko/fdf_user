/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subtract_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:30:27 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/27 15:19:35 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_subtract_point2d(t_point2d *point, t_point2d *add)
{
	point->x -= add->x;
	point->y -= add->y;
}

void	ft_subtract_point3d(t_point3d *point, t_point3d *sub)
{
	point->x -= sub->x;
	point->y -= sub->y;
	point->z -= sub->z;
}
