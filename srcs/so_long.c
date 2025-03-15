/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:00:21 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/15 17:43:45 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define TILE_SIZE 64

int main() {
    t_game game;

    // Initialize game structure and MiniLibX
    game.mlx = mlx_init();
    if (!game.mlx) {
        fprintf(stderr, "Error: mlx_init failed\n");
        return (1); // Exit with error
    }

    // Load the map from a .ber file
    game.map = load_map("./map.ber");
    if (!game.map) {
        fprintf(stderr, "Error: Failed to load map\n");
        return (1); // Exit with error
    }

    // Calculate window size dynamically based on map
    int map_width = strlen(game.map[0]);
    int map_height = 0;
    while (game.map[map_height]) map_height++;

    int window_width = map_width * TILE_SIZE;
    int window_height = map_height * TILE_SIZE;

    game.win = mlx_new_window(game.mlx, window_width, window_height, "So Long Game");
    if (!game.win) {
        fprintf(stderr, "Error: mlx_new_window failed\n");
        return (1); // Exit with error
    }

    // Load images and set tile size
    game.tile_size = TILE_SIZE;  // Set tile size to 64 for example
    load_images(&game);

    // Render the map with loaded images
    render_map(&game);

    // Start the MiniLibX event loop
    mlx_loop(game.mlx);

    return 0;
}