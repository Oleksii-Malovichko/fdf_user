/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_key_presses.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:01:49 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/28 13:59:45 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	check_camera_movement(t_fdf *fdf)
{
	t_point2d	movement;
	float		magnitude;

	ft_set_point2d(&movement, 0, 0);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A) && !mlx_is_key_down(fdf->mlx,
			MLX_KEY_D))
		movement.x = -100;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_D) && !mlx_is_key_down(fdf->mlx,
			MLX_KEY_A))
		movement.x = 100;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W) && !mlx_is_key_down(fdf->mlx,
			MLX_KEY_S))
		movement.y = -100;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_S) && !mlx_is_key_down(fdf->mlx,
			MLX_KEY_W))
		movement.y = 100;
	magnitude = ft_magnitude_point2d(&movement);
	if (magnitude <= 0)
		return ;
	ft_scale_point2d(&movement, 1 / magnitude * OFFSET_STEP);
	ft_add_point2d(&fdf->offset, &movement);
	fdf->update = true;
}

static void	check_zoom_scale_change(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		ft_zoom_out(fdf);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		ft_zoom_in(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		ft_increase_y_scale(fdf);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		ft_decrease_y_scale(fdf);
}

static void	check_viewpoint_change(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
	{
		if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT_SHIFT))
			fdf->viewpoint.x -= DEGREE_STEP;
		else
			fdf->viewpoint.x += DEGREE_STEP;
		fdf->update = true;
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_Y))
	{
		if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT_SHIFT))
			fdf->viewpoint.y -= DEGREE_STEP;
		else
			fdf->viewpoint.y += DEGREE_STEP;
		fdf->update = true;
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
	{
		if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT_SHIFT))
			fdf->viewpoint.z -= DEGREE_STEP;
		else
			fdf->viewpoint.z += DEGREE_STEP;
		fdf->update = true;
	}
}

static void	check_bonus_rotation(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
		ft_rotate_clock(fdf);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
		ft_rotate_counter(fdf);
}

void	ft_check_key_presses(t_fdf *fdf)
{
	check_camera_movement(fdf);
	check_zoom_scale_change(fdf);
	check_viewpoint_change(fdf);
	check_bonus_rotation(fdf);
}
