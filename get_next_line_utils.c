/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:22:39 by jrenault          #+#    #+#             */
/*   Updated: 2022/12/01 15:45:12 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *buf, char *line)
{
	int		i;
	int		j;
	int		cleanbuf;
	char	*concatenation;

	i = 0;
	j = 0;
	cleanbuf = 0;
	if (!buf || !line)
		return (NULL);
	concatenation = (char *)malloc(sizeof(char)
			* (ft_strlen(buf) + ft_strlen(line) + 1));
	if (!concatenation)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
	{
		concatenation[i] = buf[i];
		i++;
		cleanbuf++;
	}
	while (buf[cleanbuf])
		cleanbuf++;
	if (buf[i] == '\n')
	{
		ft_memmove_gnl(buf, &buf[i], i - cleanbuf);
	}
	while (line[j])
	{
		concatenation[i] = line[j];
		i++;
		j++;
	}
	concatenation[i] = '\0';
	return (concatenation);
}

void	ft_memmove_gnl(void *dest, void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return ;
	while (i < size)
	{
		if (dest > src)
		{
			((char *)dest)[size - 1] = ((char *)src)[size - 1];
			size--;
		}
		else
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
}

void	*ft_bzero(void *memo, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)memo)[i] = '\0';
		i++;
	}
	return (memo);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory_zone;

	if (size > 0 && count > SIZE_MAX / size)
		return (0);
	memory_zone = malloc(count * size);
	if (!memory_zone)
		return (NULL);
	ft_bzero(memory_zone, (count * size));
	return (memory_zone);
}
