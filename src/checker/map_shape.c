/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:55:03 by marvin            #+#    #+#             */
/*   Updated: 2025/10/15 23:33:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_rectangular(char **map)
{
	size_t	x;
	size_t	y;

	if (!map)
		return (0);
	if (!map[0])
		return (0);
	x = ft_strlen(map[0]);
	y = 1;
	while (map[y])
	{
		if (ft_strlen(map[y]) != x)
		{
			ft_putstr_fd("Error\nMap is not rectangular!\n", 1);
			free_tab(map);
			return (0);
		}
		y++;
	}
	return (1);
}
