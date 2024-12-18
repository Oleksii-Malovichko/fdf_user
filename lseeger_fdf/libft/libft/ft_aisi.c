/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aisi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:11:20 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/20 16:12:17 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_aisi(char *str)
{
	if (!str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != ' ' && *str != '-')
			return (false);
		str++;
	}
	return (true);
}
