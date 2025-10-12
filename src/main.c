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

int	main(void)
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	mlx_loop(mlx);
}
