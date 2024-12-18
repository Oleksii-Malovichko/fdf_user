/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:40:36 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/27 15:27:13 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_normalize_point2d(t_point2d *point)
{
	int	mag;

	mag = ft_magnitude_point2d(point);
	if (mag != 0)
	{
		point->x /= mag;
		point->y /= mag;
	}
}
