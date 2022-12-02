/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:00:02 by jrenault          #+#    #+#             */
/*   Updated: 2022/12/01 15:57:02 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			nbyte;
	char		*line;
//	int			i;

//	i = 0;
	line = ft_calloc(1, 1);
	nbyte = read(fd, buffer, BUFFER_SIZE);
	if (nbyte == -1)
		return (NULL);
	line = ft_strjoin_gnl(buffer, line);
//	printf("%s", line);
//	printf("%s", buffer);
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
