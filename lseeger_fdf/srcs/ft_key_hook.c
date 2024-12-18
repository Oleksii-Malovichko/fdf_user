/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:52:01 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/28 14:07:47 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_key_hook(mlx_key_data_t key_data, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key_data.key == MLX_KEY_R)
		ft_reset_fdf_view(fdf);
	if (key_data.key == MLX_KEY_ESCAPE)
	{
		ft_free_fdf_content(fdf);
		mlx_terminate(fdf->mlx);
		exit(0);
	}
	if (key_data.key == MLX_KEY_I)
		ft_set_isometric_projection(fdf);
	if (key_data.key == MLX_KEY_P)
		ft_set_parallel_projection(fdf);
	if (key_data.key == MLX_KEY_L)
		ft_set_perspective_projection(fdf);
	if (key_data.key == MLX_KEY_O)
		ft_set_orthographic_projection(fdf);
}
