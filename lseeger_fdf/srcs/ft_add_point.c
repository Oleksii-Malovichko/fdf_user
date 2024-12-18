/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:23:28 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/27 15:16:45 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_add_point2d(t_point2d *point, t_point2d *add)
{
	point->x += add->x;
	point->y += add->y;
}

void	ft_add_point3d(t_point3d *point, t_point3d *add)
{
	point->x += add->x;
	point->y += add->y;
	point->z += add->z;
}
