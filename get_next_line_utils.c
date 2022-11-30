/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:22:39 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/30 14:20:09 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_revchr(const char *overage, const char *stash)
{
	int		i;
	int		j;
	char	*newstring;
	char	*concatenation;

	i = 0;
	j = 0;
	if (!overage || !stash)
		return (NULL);
	newstring = ft_rev_strchr_gnl(stash, '\n');
	concatenation = (char *)malloc(sizeof(char)
			* (ft_strlen(overage) + ft_strlen(stash) + 1));
	if (!concatenation)
		return (NULL);
	while (overage[i])
	{
		concatenation[i] = overage[i];
		i++;
	}
	while (newstring[j])
	{
		concatenation[i] = newstring[j];
		i++;
		j++;
	}
	concatenation[i] = '\0';
	return (concatenation);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(((char *)src)) + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (((char *)dest));
}

char	*ft_strchr_gnl(const char *string, int searchedChar)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == ((char)searchedChar))
			return (&((char *)string)[i]);
		i++;
	}
	if (string[i] == ((char)searchedChar))
		return (&((char *)string)[i]);
	return (0);
}

char	*ft_rev_strchr_gnl(const char *string, int searchedChar)
{
	int		i;
	int		j;
	char	*newstring;

	i = 0;
	j = 0;
	newstring = (char *)malloc(sizeof(char *) * (ft_strlen(string) + 1));
	while (string[i] != searchedChar)
		i++;
	while (j < i)
	{
		newstring[j] = string[j];
		j++;
	}
	return (newstring);
}

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
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
	return (dest);
}
