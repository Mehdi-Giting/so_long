/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 05:25:23 by marvin            #+#    #+#             */
/*   Updated: 2025/10/16 06:19:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	on_key(int keycode, t_game *game)
{
	if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 100)
		move_player(game, 1, 0);
	else if (keycode == 65307)
	{
		ft_putstr_fd("ESC\n", 1);
		mlx_destroy_window(game->mlx, game->win);
		free_tab(game->map);
		exit(0);
	}
	return (0);
}
