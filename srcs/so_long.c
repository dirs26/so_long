/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:00:21 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/03 13:54:16 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

#define TILE_SIZE 64


// Function to load images
void load_images(t_game *game) {
    int width;
    int height;

    game->img_wall = mlx_xpm_file_to_image(game->mlx, "Trees.xpm", &width, &height);
    if (!game->img_wall) {
        fprintf(stderr, "Error: Failed to load Trees.xpm\n");
        exit(1); // Exit on error
    }

    game->img_floor = mlx_xpm_file_to_image(game->mlx, "Interface.xpm", &width, &height);
    if (!game->img_floor) {
        fprintf(stderr, "Error: Failed to load Interface.xpm\n");
        exit(1);
    }

    game->img_player = mlx_xpm_file_to_image(game->mlx, "PLYR.xpm", &width, &height);
    if (!game->img_player) {
        fprintf(stderr, "Error: Failed to load PLYR.xpm\n");
        exit(1);
    }

    game->img_collect = mlx_xpm_file_to_image(game->mlx, "Whiskey.xpm", &width, &height);
    if (!game->img_collect) {
        fprintf(stderr, "Error: Failed to load Whiskey.xpm\n");
        exit(1);
    }

    game->img_exit = mlx_xpm_file_to_image(game->mlx, "exit.xpm", &width, &height);
    if (!game->img_exit) {
        fprintf(stderr, "Error: Failed to load exit.xpm\n");
        exit(1);
    }
}


// Function to render the map
void render_map(t_game *game) {
    int x, y;

    for (y = 0; game->map[y]; y++) {
        for (x = 0; game->map[y][x]; x++) {
            void *img = game->img_floor; // Default to floor
            if (game->map[y][x] == '1') {
                img = game->img_wall; // Wall
            } else if (game->map[y][x] == 'P') {
                img = game->img_player; // Player
            } else if (game->map[y][x] == 'C') {
                img = game->img_collect; // Collectable
            } else if (game->map[y][x] == 'E') {
                img = game->img_exit; // Exit
            }

            if (img == NULL) {
                fprintf(stderr, "Error: NULL image for tile at (%d, %d)\n", x, y);
                continue; // Skip invalid tiles
            }

            // Place the image in the window at the appropriate position
            mlx_put_image_to_window(game->mlx, game->win, img, x * game->tile_size, y * game->tile_size);
        }
    }
}

int main() {
    t_game game;

    // Initialize game structure and MiniLibX
    game.mlx = mlx_init();
    if (!game.mlx) {
        fprintf(stderr, "Error: mlx_init failed\n");
        return (1); // Exit with error
    }

    game.win = mlx_new_window(game.mlx, 800, 600, "So Long Game");
    if (!game.win) {
        fprintf(stderr, "Error: mlx_new_window failed\n");
        return (1); // Exit with error
    }

    // Load images and set tile size
    game.tile_size = TILE_SIZE;  // Set tile size to 64 for example
    load_images(&game);

    // Initialize the map (for testing, we use a hardcoded map here)
    game.map = (char *[]) {
        "11111",
        "1P0C1",
        "1C01E",
        "11111",
        NULL
    };

    // Render the map with loaded images
    render_map(&game);

    // Start the MiniLibX event loop
    mlx_loop(game.mlx);

    return 0;
}
