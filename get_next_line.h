/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:07:34 by jrenault          #+#    #+#             */
/*   Updated: 2022/12/04 17:51:39 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *buf, char *line);
size_t	ft_strlen(const char *str);
void	*ft_bzero(void *memo, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
void	*ft_memmove(void *dest, const void *src, size_t size);

#endif