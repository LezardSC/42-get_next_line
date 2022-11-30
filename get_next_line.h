/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:07:34 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/30 08:42:09 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_revchr(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strchr_gnl(const char *string, int searchedChar);
char	*ft_rev_strchr_gnl(const char *string, int searchedChar);

#endif