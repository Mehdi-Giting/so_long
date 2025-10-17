/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:13:20 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 03:31:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// 15 is the number of tile for 960pixel window width & heigth, 
// so in order to find where the offset should start,
// i said it start at the end minus 15 (number of tile)

void	find_player_camera(t_game *game)
{
	if (ft_strlen(game->map[0]) > 15)
	{
		if (game->player_x >= 1 && game->player_x <= 8)
			game->offset_x = 0;
		else if (game->player_x <= (int)(ft_strlen(game->map[0]) - 1)
			&& game->player_x >= (int)(ft_strlen(game->map[0]) - 1 - 7))
			game->offset_x = (int)ft_strlen(game->map[0]) - 15;
		else
			game->offset_x = game->player_x - 7;
	}
	if (ft_tab_len(game->map) > 15)
	{
		if (game->player_y >= 1 && game->player_y <= 7)
			game->offset_y = 0;
		else if (game->player_y <= (ft_tab_len(game->map) - 2)
			&& game->player_y >= (ft_tab_len(game->map) - 2 - 7))
			game->offset_y = ft_tab_len(game->map) - 15;
		else
			game->offset_y = game->player_y - 7;
	}
}

void	render_tile_wall_responsive(t_game *game, int x, int y)
{
	if (y == 0 && x > 0 && x < ((int)ft_strlen(game->map[y]) - 1)
		&& game->map[y + 1][x] != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall_side,
			game->sx, game->sy);
	else if (y == (ft_tab_len(game->map) - 1))
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall_side,
			game->sx, game->sy);
	else if (y > 0 && y < (ft_tab_len(game->map) - 1)
		&& x > 0 && x < ((int)ft_strlen(game->map[y]) - 1)
		&& game->map[y + 1][x] != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall_side,
			game->sx, game->sy);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
			game->sx, game->sy);
}

void	render_tile_player_responsive(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = (game->player_x - game->offset_x) * TILE_SIZE;
	py = (game->player_y - game->offset_y) * TILE_SIZE;
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player_on_grave,
			px, py);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_player_on_ground,
			px, py);
}

void	render_tile_responsive(t_game *game, int x, int y)
{
	char	c;

	c = game->map[y][x];
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible,
			game->sx, game->sy);
	if (c == '1')
		render_tile_wall_responsive(game, x, y);
	if (c == 'E')
	{
		if (game->collectible_count == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->img_exit_open,
				game->sx, game->sy);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_exit_close,
				game->sx, game->sy);
	}
	render_tile_player_responsive(game, game->player_x, game->player_y);
}

void	render_responsive(t_game *game)
{
	int	y;
	int	x;
	int	i;
	int	j;

	find_player_camera(game);
	y = game->offset_y;
	i = 0;
	while (game->map[y] && i < 15)
	{
		j = 0;
		x = game->offset_x;
		while (game->map[y][x] && j < 15)
		{
			game->sx = (x - game->offset_x) * TILE_SIZE;
			game->sy = (y - game->offset_y) * TILE_SIZE;
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_floor, game->sx, game->sy);
			render_tile_responsive(game, x, y);
			x++;
			j++;
		}
		i++;
		y++;
	}
}
