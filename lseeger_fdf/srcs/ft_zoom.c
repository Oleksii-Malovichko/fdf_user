/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:02:02 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/26 13:37:56 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_update_zoom_factor(t_fdf *fdf)
{
	if (fdf->zoom <= MIN_ZOOM)
		fdf->zoom = MIN_ZOOM;
	else if (fdf->zoom >= MAX_ZOOM)
		fdf->zoom = MAX_ZOOM;
	fdf->tile_size = TILE_SIZE * fdf->zoom;
	fdf->update = true;
}

void	ft_zoom_in(t_fdf *fdf)
{
	fdf->zoom += ZOOM_STEP;
	ft_update_zoom_factor(fdf);
}

void	ft_zoom_out(t_fdf *fdf)
{
	fdf->zoom -= ZOOM_STEP;
	ft_update_zoom_factor(fdf);
}
