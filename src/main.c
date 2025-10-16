/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 01:57:05 by marvin            #+#    #+#             */
/*   Updated: 2025/10/11 01:57:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_tab(game->map);
	exit(0);
	return (0);
}

void	cleanup_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_wall_side);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_collectible);
	mlx_destroy_image(game->mlx, game->img_exit_close);
	mlx_destroy_image(game->mlx, game->img_player_on_ground);
	mlx_destroy_image(game->mlx, game->img_player_on_grave);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./so_long <map.ber>\n", 1);
		return (1);
	}
	if (ac == 2)
	{
		if (!is_valid_map(av[1]))
		{
			ft_putstr_fd("Error\nInvalid map\n", 1);
			return (1);
		}
		init_mlx(&game, av[1]);
		load_textures(&game);
		find_player_position(&game);
		game.collectible_count = count_collectibles(game.map);
		render(&game);
		mlx_hook(game.win, 2, 1L << 0, on_key, &game);
		mlx_hook(game.win, 17, 0, close_window, &game);
		mlx_loop(game.mlx);
		cleanup_game(&game);
	}
	return (0);
}
