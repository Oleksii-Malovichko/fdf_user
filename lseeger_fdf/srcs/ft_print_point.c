/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:03:21 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/25 15:05:39 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_print_point2d(char *name, t_point2d *point)
{
	ft_printf("%s(%i|%i)\n", name, point->x, point->y);
}

void	ft_print_point3d(char *name, t_point3d *point)
{
	ft_printf("%s(%i|%i|%i)\n", name, point->x, point->y, point->z);
}
