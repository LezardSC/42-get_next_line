/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:07:34 by jrenault          #+#    #+#             */
/*   Updated: 2022/12/01 15:44:56 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 55
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(const char *buf, const char *line);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
void	*ft_memmove_gnl(void *dest, const void *src, size_t size);

#endif