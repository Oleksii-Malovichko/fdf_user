/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:21:40 by lseeger           #+#    #+#             */
/*   Updated: 2024/12/04 13:13:01 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *msg)
{
	int	has_error;

	has_error = 0;
	if (msg != NULL)
	{
		ft_printf("Custom Error: %s\n", msg);
		has_error = 1;
	}
	if (errno != 0)
	{
		ft_printf("Default Error: %s\n", strerror(errno));
		has_error = 1;
	}
	if (mlx_errno != 0)
	{
		ft_printf("MLX42 Error: %s\n", mlx_strerror(mlx_errno));
		has_error = 1;
	}
	if (!has_error)
	{
		ft_printf("ft_error called without error...\n");
	}
	exit(EXIT_FAILURE);
}
// system("leaks fdf");
