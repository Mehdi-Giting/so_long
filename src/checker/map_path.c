/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:41:39 by marvin            #+#    #+#             */
/*   Updated: 2025/10/15 23:42:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**map_dup(char **map)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc(sizeof(char *) * (ft_tab_len(map) + 1));
	if (!new_map)
		return (NULL);
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			while (new_map[i])
				free(new_map[i]);
			free(new_map);
			return (0);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

int	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	flood_fill(char **map, int x, int y)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	has_unreachable_elements(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_path_valid(char **map)
{
	char	**copy;
	int		x;
	int		y;

	if (!map)
		return (0);
	copy = map_dup(map);
	if (!copy)
		return (0);
	if (!find_player(copy, &x, &y))
		return (0);
	flood_fill(copy, x, y);
	if (has_unreachable_elements(copy) == 1)
	{
		ft_putstr_fd("Error\nMap has no valid path for the player!\n", 1);
		free_tab(map);
		free_tab(copy);
		return (0);
	}
	free_tab(copy);
	return (1);
}
