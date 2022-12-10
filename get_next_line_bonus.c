/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:15:01 by jrenault          #+#    #+#             */
/*   Updated: 2022/12/10 10:45:35 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	is_backslash_n(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
	{
		return (0);
	}
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (BUFFER_SIZE);
}

static char	*get_line(char *buffer, char *line)
{
	int	i;

	i = is_backslash_n(buffer);
	line = ft_strnjoin_gnl(buffer, line, i + 1);
	buffer = ft_memmove(buffer, buffer + i + 1, BUFFER_SIZE - i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			nbyte;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (buffer[fd][0] != '\0')
	{
		if (is_backslash_n(buffer[fd]) != BUFFER_SIZE)
			return (get_line(buffer[fd], line));
		line = ft_strnjoin_gnl(buffer[fd], line, BUFFER_SIZE);
	}
	nbyte = read(fd, buffer[fd], BUFFER_SIZE);
	if (nbyte < 0)
		return (ft_memset(buffer[fd], 0, BUFFER_SIZE), free(line), NULL);
	while (nbyte)
	{
		buffer[fd][nbyte] = '\0';
		if (is_backslash_n(buffer[fd]) != BUFFER_SIZE)
			return (get_line(buffer[fd], line));
		line = ft_strnjoin_gnl(buffer[fd], line, BUFFER_SIZE);
		nbyte = read(fd, buffer[fd], BUFFER_SIZE);
	}
	return (ft_memset(buffer[fd], 0, BUFFER_SIZE), line);
}
