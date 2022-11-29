/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:22:39 by jrenault          #+#    #+#             */
/*   Updated: 2022/11/29 13:36:25 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*concatenation;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	concatenation = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!concatenation)
		return (NULL);
	while (s1[i])
	{
		concatenation[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		concatenation[i] = s2[j];
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
