/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:24:47 by marvin            #+#    #+#             */
/*   Updated: 2025/10/11 16:24:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**parse(char *filename)
{
	int		fd;
	char	*line;
	char	*final_line;
	char	**map;

	fd = open(filename, O_RDONLY);
	final_line = NULL;
	if (fd == -1)
		return (0);
	while((line = get_next_line(fd)) != NULL)
	{
		final_line = gnl_strjoin(final_line, line);
		free(line);
	}
	map = ft_split(final_line, '\n');
	free(final_line);
	return (map);
}