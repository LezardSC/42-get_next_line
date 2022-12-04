/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:04:59 by jrenault          #+#    #+#             */
/*   Updated: 2022/12/04 18:01:24 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	search_backslash_n(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (0);
		i++;
	}
	if (buffer[i] == '\n')
		return (0);
	return (1);
}

void	clean_buffer(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	ft_memmove(buffer, buffer + i, BUFFER_SIZE - i + 1);
	printf("%s", buffer);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			nbyte;

	line = ft_calloc(1, 1);
	nbyte = 1;
	while (search_backslash_n(buffer))
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin_gnl(buffer, line);
		clean_buffer(buffer);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	int		i;

	fd = open("LeCorbeauEtLeRenard.txt", O_RDONLY);
	i = 1;
	while (i > 0)
	{
		get_next_line(fd);
//		printf("%s", get_next_line(fd));
		i--;
	}
	close(fd);
}
