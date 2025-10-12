/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:07:00 by ellabiad          #+#    #+#             */
/*   Updated: 2025/10/11 16:04:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_stash(char *buffer, char *stash, int fd)
{
	int	byte_read;

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (NULL);
		buffer[byte_read] = '\0';
		stash = gnl_strjoin(stash, buffer);
		if (gnl_strchr(buffer, '\n') != NULL)
			break ;
	}
	return (stash);
}

char	*fill_line(char **stash_ptr)
{
	char	*line;
	char	*new_stash;
	char	*stash;
	int		i;

	i = 0;
	stash = *stash_ptr;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		line = gnl_substr(stash, 0, i + 1);
	else
		line = gnl_substr(stash, 0, i);
	if (stash[i] == '\n')
		new_stash = gnl_substr(stash, i + 1, gnl_strlen(stash) - i);
	else
		new_stash = NULL;
	free(*stash_ptr);
	*stash_ptr = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash[1024] = {NULL};

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash[fd] = fill_stash(buffer, stash[fd], fd);
	free(buffer);
	if (!stash[fd] || stash[fd][0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	if (!stash[fd])
		return (NULL);
	line = fill_line(&stash[fd]);
	return (line);
}
