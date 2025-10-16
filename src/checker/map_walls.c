/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:43:36 by marvin            #+#    #+#             */
/*   Updated: 2025/10/16 06:19:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_tab_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	is_closed_by_walls_conditions(char **map, int i, int j, int tab_len)
{
	if (i == 0 || i == tab_len - 1)
	{
		while (map[i][j])
		{
			if (map[i][j] != '1')
			{
				free_tab(map);
				return (0);
			}
			j++;
		}
	}
	if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
	{
		free_tab(map);
		return (0);
	}
	return (1);
}

int	is_closed_by_walls(char **map)
{
	int	i;
	int	j;
	int	tab_len;

	i = 0;
	tab_len = ft_tab_len(map);
	while (map[i])
	{
		j = 0;
		if (is_closed_by_walls_conditions(map, i, j, tab_len) == 0)
		{
			ft_putstr_fd("Error\nMap is not closed by walls!\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}
