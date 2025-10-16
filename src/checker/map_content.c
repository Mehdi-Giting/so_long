/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:58:44 by marvin            #+#    #+#             */
/*   Updated: 2025/10/16 05:56:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	has_valid_chars(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		while (map[i][j])
		{
			c = map[i][j];
			if (!(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'))
			{
				free_tab(map);
				ft_putstr_fd("Error\nMap contains invalid characters!\n", 1);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	has_valid_counts_loop(t_count *count, char **map)
{
	while (map[count->i])
	{
		count->j = 0;
		while (map[count->i][count->j])
		{
			if (map[count->i][count->j] == 'P')
				count->player++;
			if (map[count->i][count->j] == 'E')
				count->exit++;
			if (map[count->i][count->j] == 'C')
				count->collectibles++;
			count->j++;
		}
		count->i++;
	}
}

int	has_valid_counts(char **map)
{
	t_count	count;

	count.i = 0;
	count.exit = 0;
	count.player = 0;
	count.collectibles = 0;
	has_valid_counts_loop(&count, map);
	if (count.player != 1 || count.exit != 1 || count.collectibles < 1)
	{
		ft_putstr_fd("Error\nMap contains invalid number of P, E or C!\n", 1);
		free_tab(map);
		return (0);
	}
	return (1);
}
