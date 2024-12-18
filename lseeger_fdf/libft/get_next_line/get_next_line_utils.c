/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:55 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/20 15:57:15 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

char	*get_next_nl(char *s)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE && s[i])
	{
		if (s[i] == '\n')
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*rstr(const char *s, size_t *nl_r_len)
{
	char			*new_str;
	const size_t	s_len = ft_strlen(s);

	if (*nl_r_len < s_len)
		*nl_r_len = s_len;
	new_str = malloc(*nl_r_len + 1);
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, s, s_len);
	new_str[s_len] = 0;
	return (new_str);
}

bool	buffer_join(char **nl, char const *buffer, size_t *nl_r_len)
{
	const size_t	nl_len = ft_strlen(*nl);
	const size_t	buffer_len = ft_strlen(buffer);
	char			*new_str;

	if (!*nl)
	{
		*nl_r_len = BUFFER_SIZE * 2;
		*nl = rstr(buffer, nl_r_len);
		return (false);
	}
	else if (nl_len + buffer_len < *nl_r_len)
	{
		ft_memmove(*nl + nl_len, buffer, buffer_len);
		(*nl)[nl_len + buffer_len] = 0;
		return (false);
	}
	*nl_r_len = buffer_len + (nl_len * 2);
	new_str = malloc(*nl_r_len + 1);
	if (!new_str)
		return (failure_cleanup(*nl), true);
	ft_memmove(new_str, *nl, nl_len);
	ft_memmove(new_str + nl_len, buffer, buffer_len + 1);
	free(*nl);
	*nl = new_str;
	return (false);
}

void	failure_cleanup(char *nl)
{
	if (nl)
		free(nl);
}
