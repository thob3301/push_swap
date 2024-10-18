/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:41:38 by miteixei          #+#    #+#             */
/*   Updated: 2024/10/17 17:02:54 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// create a static buffer
// 
// check if file descriptor has no errors
// else clear buffer and return NULL
//
// while first byte in buffer is not zero or file is read onto buffer
// add buffer to return string
// clean buffer until a possible newline and copy remaing contents to the start
// return string if the last character is a newline

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = _ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
		_ft_clean_buff(buffer);
		if (str[_ft_strlen(str) - 1] == '\n')
			return (str);
	}
	return (str);
}
