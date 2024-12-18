/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_in_area.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:46:14 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/25 13:46:47 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

bool	ft_point_in_area(int width, int height, t_point2d *point)
{
	if (point->x < 0 || point->x >= width)
		return (false);
	if (point->y < 0 || point->y >= height)
		return (false);
	return (true);
}
