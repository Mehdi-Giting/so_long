/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 00:11:24 by marvin            #+#    #+#             */
/*   Updated: 2025/10/16 23:37:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	init_mlx_window(t_game *game)
{
	if ((ft_strlen(game->map[0]) * TILE_SIZE) > 960)
		game->width = 960;
	else
		game->width = ft_strlen(game->map[0]) * TILE_SIZE;
	if ((ft_tab_len(game->map) * TILE_SIZE) > 960)
		game->heigth = 960;
	else
		game->heigth = ft_tab_len(game->map) * TILE_SIZE;
}

void	init_mlx(t_game *game, char *filename)
{
	game->map = read_file(filename);
	if (!game->map)
	{
		ft_putstr_fd("Error\nFailed to load map\n", 1);
		return ;
	}
	init_mlx_window(game);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nMLX initialization failed\n", 1);
		return ;
	}
	game->win = mlx_new_window(game->mlx, game->width, game->heigth, "so_long");
	if (!game->win)
	{
		ft_putstr_fd("Error\nWindow creation failed\n", 1);
		return ;
	}
	game->collectible_count = count_collectibles(game->map);
	game->step_count = 0;
}

int	load_condition(t_game *game)
{
	if (!game->img_wall || !game->img_wall_side || !game->img_floor
		|| !game->img_collectible || !game->img_exit_close
		|| !game->img_exit_open || !game->img_player_on_ground
		|| !game->img_player_on_grave)
	{
		ft_putstr_fd("Error\nFailed to load one or more textures\n", 1);
		return (0);
	}
	return (1);
}

void	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &w, &h);
	game->img_wall_side = mlx_xpm_file_to_image(game->mlx,
			"textures/wall_side.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/ground.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/colectible.xpm", &w, &h);
	game->img_exit_close = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_close.xpm", &w, &h);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_open.xpm", &w, &h);
	game->img_player_on_ground = mlx_xpm_file_to_image(game->mlx,
			"textures/player_on_ground.xpm", &w, &h);
	game->img_player_on_grave = mlx_xpm_file_to_image(game->mlx,
			"textures/player_on_grave.xpm", &w, &h);
	if (load_condition(game) == 0)
		return ;
}
