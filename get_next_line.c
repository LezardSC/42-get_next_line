/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:00:02 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/30 14:45:41 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_read_file(int fd, char *buf)
{
	char	*temp;
	int		nbyte;

	if (!buf)
		buf = malloc(1);
	temp = (char *)malloc(sizeof(char *) + (BUFFER_SIZE + 1));
	nbyte = read(fd, buf, BUFFER_SIZE);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (!fd || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	ft_read_file(fd, buf);
}

int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	fd = open("Test1.txt", O_RDONLY);
	i = 2;
	while (i > 0)
	{
		str = get_next_line(fd);
		printf("%s", str);
		i--;
	}
	close(fd);
}
