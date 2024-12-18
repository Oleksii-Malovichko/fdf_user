/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:43:28 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/28 14:06:27 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_set_isometric_projection(t_fdf *fdf)
{
	ft_printf("isometric projection\n");
	fdf->projection_func = ft_get_isometric;
	fdf->update = true;
}

void	ft_set_parallel_projection(t_fdf *fdf)
{
	ft_printf("parallel projection\n");
	fdf->projection_func = ft_get_parallel;
	fdf->update = true;
}

void	ft_set_perspective_projection(t_fdf *fdf)
{
	ft_printf("perspective projection\n");
	fdf->projection_func = ft_get_perspective;
	fdf->update = true;
}

void	ft_set_orthographic_projection(t_fdf *fdf)
{
	ft_printf("orthographic projection\n");
	fdf->projection_func = ft_get_orthographic;
	fdf->update = true;
}
