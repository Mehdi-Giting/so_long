/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 00:11:31 by marvin            #+#    #+#             */
/*   Updated: 2025/10/16 06:35:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	render_tile_wall(t_game *game, int x, int y)
{
	if (y == 0 && x > 0 && x < ((int)ft_strlen(game->map[y]) - 1)
		&& game->map[y + 1][x] != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall_side,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (y == (ft_tab_len(game->map) - 1))
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall_side,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (y > 0 && y < (ft_tab_len(game->map) - 1)
		&& x > 0 && x < ((int)ft_strlen(game->map[y]) - 1)
		&& game->map[y + 1][x] != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall_side,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	render_tile_player(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player_on_grave,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_player_on_ground,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	render_tile(t_game *game, int x, int y)
{
	char	c;

	c = game->map[y][x];
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible,
			x * TILE_SIZE, y * TILE_SIZE);
	if (c == '1')
		render_tile_wall(game, x, y);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit_close,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	render(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
				x * TILE_SIZE, y * TILE_SIZE);
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
	render_tile_player(game, game->player_x, game->player_y);
}
