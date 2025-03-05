/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:00:21 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/05 14:10:49 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TILE_SIZE 64

// Function to load map dynamically
char **load_map(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening map file");
        return NULL;
    }

    char **map = malloc(sizeof(char *) * 10);  // Start with space for 10 lines
    if (!map)
    {
        perror("Error allocating memory for map");
        close(fd);
        return NULL;
    }

    char *line;
    int i = 0;
    int map_size = 10;  // Initial map size
    while ((line = get_next_line(fd)) != NULL)
    {
        if (i >= map_size)
        {
            map_size *= 2;  // Double the map size when needed
            map = realloc(map, sizeof(char *) * map_size);
            if (!map)
            {
                perror("Error reallocating memory for map");
                close(fd);
                return NULL;
            }
        }

        map[i] = line;  // Store each line
        i++;
    }

    map[i] = NULL;  // Null-terminate the map array
    close(fd);
    return map;
}

// Function to load images (as previously defined)
void load_images(t_game *game) {
    int width;
    int height;

    game->img_wall = mlx_xpm_file_to_image(game->mlx, "imgs/Trees.xpm", &width, &height);
    if (!game->img_wall) {
        fprintf(stderr, "Error: Failed to load Trees.xpm\n");
        exit(1); // Exit on error
    }

    game->img_floor = mlx_xpm_file_to_image(game->mlx, "imgs/Interface.xpm", &width, &height);
    if (!game->img_floor) {
        fprintf(stderr, "Error: Failed to load Interface.xpm\n");
        exit(1);
    }

    game->img_player = mlx_xpm_file_to_image(game->mlx, "imgs/PLYR.xpm", &width, &height);
    if (!game->img_player) {
        fprintf(stderr, "Error: Failed to load PLYR.xpm\n");
        exit(1);
    }

    game->img_collect = mlx_xpm_file_to_image(game->mlx, "imgs/Whiskey.xpm", &width, &height);
    if (!game->img_collect) {
        fprintf(stderr, "Error: Failed to load Whiskey.xpm\n");
        exit(1);
    }

    game->img_exit = mlx_xpm_file_to_image(game->mlx, "imgs/exit.xpm", &width, &height);
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
