/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_fdf_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:03:14 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/22 14:53:54 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_free_fdf_content(t_fdf *fdf)
{
	ft_free_map_content(&fdf->map);
	if (fdf->img)
		mlx_delete_image(fdf->mlx, fdf->img);
	mlx_terminate(fdf->mlx);
}
