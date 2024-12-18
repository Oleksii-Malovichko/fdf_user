/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_fdf_view.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:53:02 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/28 14:02:30 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_reset_fdf_view(t_fdf *fdf)
{
	fdf->update = true;
	fdf->projection_func = ft_get_isometric;
	fdf->tile_size = TILE_SIZE;
	fdf->offset.x = ft_get_screen_middle_offset_x(fdf);
	fdf->offset.y = ft_get_screen_middle_offset_y(fdf);
	ft_set_point3d_d(&fdf->viewpoint, 0, 0, 0);
	fdf->zoom = START_ZOOM;
	ft_update_zoom_factor(fdf);
	fdf->y_scale = START_Y_SCALE;
	ft_set_isometric_projection(fdf);
}
