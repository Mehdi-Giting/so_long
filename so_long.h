/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 01:17:57 by marvin            #+#    #+#             */
/*   Updated: 2025/10/11 01:17:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "fcntl.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "minilibx-linux/mlx.h"

#ifndef TILE_SIZE
	# define TILE_SIZE 64
#endif

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_wall_side;
	void	*img_floor;
	void	*img_collectible;
	void	*img_exit_close;
	void	*img_exit_open;
	void	*img_player_on_ground;
	void	*img_player_on_grave;
	char	**map;
	int		width;
	int		heigth;
	int		player_x;
	int		player_y;
	int		offset_x;
	int		offset_y;
	int		collectible_count;
	int		step_count;
	int 	sx;
	int		sy;
}	t_game;

typedef struct s_count {
	int	i;
	int	j;
	int	exit;
	int	player;
	int	collectibles;
}   t_count;

// checker
int 	is_valid_map(char *filename);
int 	is_rectangular(char **map);
int		has_valid_counts(char **map);
int 	has_valid_chars(char **map);
int 	is_closed_by_walls(char **map);
int 	is_path_valid(char **map);
int		has_valid_extension(char *filename);
int		is_readable_file(char *filename);
int		ft_tab_len(char **map);
void	free_tab(char **map);
char	**read_file(char *filename);

//	init
int		count_collectibles(char **map);
void	init_mlx(t_game *game, char *filename);
void	load_textures(t_game *game);

//	render
void	render(t_game *game);
void	find_player_camera(t_game *game);
void	render_responsive(t_game *game);
// core
void	find_player_position(t_game *game);

// hooks
int		on_key(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);

#endif