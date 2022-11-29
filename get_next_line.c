/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:00:02 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/29 15:33:17 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			count_byte;
	char		buf[BUFFER_SIZE + 1];
	char		*stash;
	char		*line;
	static char	*overage = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!stash)
		return (NULL);
	line = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	count_byte = read(fd, buf, BUFFER_SIZE);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	i = 2;
	fd = open("Test1.txt", O_RDONLY);
	while (i > 0)
	{
		str = get_next_line(fd);
//		printf("%s", str);
//		printf("\n---\n");
		i--;
	}
	close(fd);
}
