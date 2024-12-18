/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_fdf_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:41:10 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/25 13:54:33 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_update_fdf_img(t_fdf *fdf)
{
	if (fdf->img)
		mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	if (!fdf->mlx || (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0))
	{
		ft_free_fdf_content(fdf);
		ft_error("Failed to update fdf img!");
	}
	fdf->update = true;
}
