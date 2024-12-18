/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_save.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:53:36 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/20 13:58:41 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

bool	ft_put_pixel_save(mlx_image_t *img, t_point2d *point, uint32_t color)
{
	if (point->x < 0 || (uint32_t)point->x >= img->width || point->y < 0
		|| (uint32_t)point->y >= img->height)
		return (false);
	mlx_put_pixel(img, point->x, point->y, color);
	return (true);
}
