/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:17:56 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/27 15:54:01 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_update_degree(t_fdf *fdf)
{
	if (fdf->viewpoint.x < MIN_RADIANT)
		fdf->viewpoint.x += M_PI * 2;
	else if (fdf->viewpoint.x > MAX_RADIANT)
		fdf->viewpoint.x -= M_PI * 2;
	if (fdf->viewpoint.y < MIN_RADIANT)
		fdf->viewpoint.y += M_PI * 2;
	else if (fdf->viewpoint.y > MAX_RADIANT)
		fdf->viewpoint.y -= M_PI * 2;
	if (fdf->viewpoint.z < MIN_RADIANT)
		fdf->viewpoint.z += M_PI * 2;
	else if (fdf->viewpoint.z > MAX_RADIANT)
		fdf->viewpoint.z -= M_PI * 2;
	fdf->update = true;
}

// printf("x: %f, y: %f, z: %f\n", fdf->viewpoint.x, fdf->viewpoint.y,
// 	fdf->viewpoint.z);

void	ft_rotate_counter(t_fdf *fdf)
{
	fdf->viewpoint.z += DEGREE_STEP;
	ft_update_degree(fdf);
}

void	ft_rotate_clock(t_fdf *fdf)
{
	fdf->viewpoint.z -= DEGREE_STEP;
	ft_update_degree(fdf);
}
