/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:21:17 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/17 17:03:42 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// line counter that stops at newline or nullbyte
// ft_strlen
//
// copy characters from source to destination,
// until encountering a newline or nullbyte
// ft_strcpy
//
// copy size number of characters from source to destination or until nullbyte
// ft_strlcpy
//
// join the buffer to the line string and return it with memory allocation
// ft_strjoin

#include "get_next_line.h"

size_t	_ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		++i;
	if (s && s[i] == '\n')
		++i;
	return (i);
}

static size_t	_ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (_ft_strlen(src));
	while (src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		++i;
	}
	if (src[i] == '\n')
		dst[i++] = '\n';
	dst[i] = '\0';
	return (i);
}

size_t	_ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src || !size)
		return (_ft_strlen(src));
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (i);
}

char	*_ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	offset;

	if (!s2)
		return (NULL);
	s1_len = _ft_strlen(s1);
	s2_len = _ft_strlen(s2);
	str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	offset = _ft_strcpy(str, s1);
	_ft_strcpy(&str[offset], s2);
	if (s1)
		free(s1);
	return (str);
}

void	_ft_clean_buff(char *buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buff[i] != '\n' && i < BUFFER_SIZE)
		buff[i++] = '\0';
	if (buff[i] == '\n')
	{
		buff[i++] = '\0';
		while (i < BUFFER_SIZE)
		{
			buff[j++] = buff[i];
			buff[i++] = '\0';
		}
	}
}
