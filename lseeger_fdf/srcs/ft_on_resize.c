/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:40:24 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/27 13:34:17 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_on_resize(int32_t width, int32_t height, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->offset.x -= ft_get_screen_middle_offset_x(fdf);
	fdf->offset.y -= ft_get_screen_middle_offset_y(fdf);
	fdf->width = width;
	fdf->height = height;
	fdf->offset.x += ft_get_screen_middle_offset_x(fdf);
	fdf->offset.y += ft_get_screen_middle_offset_y(fdf);
	ft_update_fdf_img(fdf);
	fdf->update = true;
}
