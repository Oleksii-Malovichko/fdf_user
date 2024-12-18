/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:45:04 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/26 15:57:12 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_update_y_scale(t_fdf *fdf)
{
	if (fdf->y_scale <= MIN_Y_SCALE)
		fdf->y_scale = MIN_Y_SCALE;
	else if (fdf->y_scale >= MAX_Y_SCALE)
		fdf->y_scale = MAX_Y_SCALE;
	fdf->update = true;
}

void	ft_increase_y_scale(t_fdf *fdf)
{
	fdf->y_scale += SCALE_STEP;
	ft_update_y_scale(fdf);
}

void	ft_decrease_y_scale(t_fdf *fdf)
{
	fdf->y_scale -= SCALE_STEP;
	ft_update_y_scale(fdf);
}
