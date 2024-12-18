/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_screen_middle_offset.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:32:23 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/27 13:32:52 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_get_screen_middle_offset_x(t_fdf *fdf)
{
	return (-fdf->width / 2);
}

int	ft_get_screen_middle_offset_y(t_fdf *fdf)
{
	return (-fdf->height / 2);
}
