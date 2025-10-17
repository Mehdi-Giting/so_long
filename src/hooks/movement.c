/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 05:33:14 by marvin            #+#    #+#             */
/*   Updated: 2025/10/16 23:35:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->collectible_count = game->collectible_count - 1;
	}
	if (game->map[new_y][new_x] == 'E' && game->collectible_count == 0)
	{
		ft_putstr_fd("You won!\n", 1);
		mlx_destroy_window(game->mlx, game->win);
		free_tab(game->map);
		exit(0);
	}
	game->player_x = new_x;
	game->player_y = new_y;
	render(game);
	game->step_count = game->step_count + 1;
	ft_putnbr_fd(game->step_count, 1);
	ft_putchar_fd('\n', 1);
}
