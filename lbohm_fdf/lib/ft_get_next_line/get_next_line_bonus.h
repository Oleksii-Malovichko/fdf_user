/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:15:06 by lbohm             #+#    #+#             */
/*   Updated: 2024/09/11 15:41:53 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_file(int fd, char *buffer, int *byt_size);
char	*strjoin(char *newline, char *buffer);
char	*clean_buffer(char *buffer);
char	*next_line(char *buffer);
char	*ft_strchr(const char *word, int letter);
size_t	ft_len(const char *str);
size_t	ft_strlc(char *dst, const char *src, size_t size);
char	*freeup(char *buffer);

#endif