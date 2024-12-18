/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_tiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:20:50 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/27 15:21:23 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	print_action(t_point3d *start_pos, t_point3d *end_pos,
// 		t_point2d *start_pxl, t_point2d *end_pxl)
// {
// 	ft_printf("-------------------------\n");
// 	ft_print_point3d("start_pos", start_pos);
// 	ft_print_point3d("end_pos", end_pos);
// 	ft_print_point2d("start_pxl", start_pxl);
// 	ft_print_point2d("end_pxl", end_pxl);
// }

void	ft_connect_tiles(t_fdf *fdf, t_point2d *start, t_point2d *end)
{
	t_point3d	start_pos;
	t_point3d	end_pos;
	t_point2d	start_pxl;
	t_point2d	end_pxl;

	start_pos = ft_get_point(fdf, start);
	end_pos = ft_get_point(fdf, end);
	ft_rotate_point(&start_pos, &fdf->viewpoint);
	ft_rotate_point(&end_pos, &fdf->viewpoint);
	fdf->projection_func(&start_pos, &start_pxl);
	fdf->projection_func(&end_pos, &end_pxl);
	ft_subtract_point2d(&start_pxl, &fdf->offset);
	ft_subtract_point2d(&end_pxl, &fdf->offset);
	ft_draw_line(fdf->img, &start_pxl, &end_pxl,
		fdf->map.color[start->x][start->y]);
}

// if (ft_draw_line(fdf->img, &start_pxl, &end_pxl,
// 		fdf->map.color[start->x][start->y]))
// 	print_action(&start_pos, &end_pos, &start_pxl, &end_pxl);
