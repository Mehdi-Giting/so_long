/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:43:02 by marvin            #+#    #+#             */
/*   Updated: 2025/10/16 00:05:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	has_valid_extension(char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len > 4 && (ft_strncmp(filename + (len - 4), ".ber", len) == 4))
	{
		ft_putstr_fd("Error\nCannot open file!\n", 1);
		return (0);
	}
	return (1);
}

int	is_readable_file(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nCannot open file!\n", 1);
		return (0);
	}
	close(fd);
	return (1);
}

char	**read_file(char *filename)
{
	int		fd;
	char	*line;
	char	*final_line;
	char	**map;

	line = NULL;
	final_line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		final_line = gnl_strjoin(final_line, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!final_line || final_line[0] == '\0')
		return (NULL);
	map = ft_split(final_line, '\n');
	free(final_line);
	return (map);
}

void	free_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	is_valid_map(char *filename)
{
	char	**map;

	if (!has_valid_extension(filename))
		return (0);
	if (!is_readable_file(filename))
		return (0);
	map = read_file(filename);
	if (!map)
	{
		ft_putstr_fd("Error\nEmpty or unreadable map!\n", 1);
		return (0);
	}
	if (!is_rectangular(map))
		return (0);
	if (!has_valid_chars(map))
		return (0);
	if (!has_valid_counts(map))
		return (0);
	if (!is_closed_by_walls(map))
		return (0);
	if (!is_path_valid(map))
		return (0);
	free_tab(map);
	return (1);
}
