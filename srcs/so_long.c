/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:00:21 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/15 23:53:42 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# define TILE_SIZE 64

int	main(int argc, char *argv[])
{
	t_game	game;

	check_map(argc, argv[1], &game);
	game.mlx = mlx_init();
	game.size_x = game.columns * 64;
	game.size_y = game.rows * 64;
	game.win = mlx_new_window(game.mlx, game.size_x, game.size_y, "so_long");
	load_images(&game);
	place_textures(&game);
	mlx_key_hook(game.win, loop, &game);
	//mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
