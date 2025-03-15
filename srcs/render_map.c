/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:22:07 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/15 17:30:28 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_map(t_game *game) {
	void *img;

    int x, y;

    for (y = 0; game->map[y]; y++) {
        for (x = 0; game->map[y][x]; x++) {
            if (game->map[y][x] == '1') {
                img = game->img_wall;
            } else if (game->map[y][x] == 'P') {
                img = game->img_player;
            } else if (game->map[y][x] == 'C') {
                img = game->img_collect;
            } else if (game->map[y][x] == 'E') {
                img = game->img_exit;
            }

            // Place the image in the window at the appropriate position
            mlx_put_image_to_window(game->mlx, game->win, img, x * game->tile_size, y * game->tile_size);
        }
    }
}