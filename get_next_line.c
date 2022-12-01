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

void	ft_read_file(int fd, char *buf)
{
	int		nbyte;

	nbyte = 1;
	if (!(buf[0] == '\0'))
	{
		buf[0] = '\0';
		return ;
	}
	nbyte = read(fd, buf, BUFFER_SIZE);
	if (nbyte == -1)
	{
		buf[0] = '\0';
		return ;
	}
}

char	*get_line(char *buf)
{
	char	*line;
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char *));
	if (!line)
		return (NULL);
	line = ft_memmove_gnl(line, buf, i);
	line[i] = '\0';
	return (line);
}

void	*get_next(char *buf)
{
	char	*temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (NULL);
	temp = (char *)malloc(sizeof(char *) * (ft_strlen(buf) - i + 1));
	while (buf[i])
		temp[j++] = buf[i++];
	temp[j] = '\0';
	while (temp[k])
	{
		buf[k] = temp[k];
		k++;
	}
	buf[k] = '\0';
	free(temp);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	if (!fd || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	ft_read_file(fd, buf);
	line = get_line(buf);
	get_next(buf);
	printf("\n\nline : %s\n\n", line);
	line = ft_strjoin_gnl(line, buf);
	return (line);
}

int	main(void)
{
	int		fd;
	int		i;

	fd = open("LeCorbeauEtLeRenard.txt", O_RDONLY);
	i = 50;
	while (i > 0)
	{
		printf("%s", get_next_line(fd));
		i--;
	}
	close(fd);
}
