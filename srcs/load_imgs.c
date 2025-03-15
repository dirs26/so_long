/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:21:04 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/15 17:25:23 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_images(t_game *game) {
    int width;
    int height;

    game->img_wall = mlx_xpm_file_to_image(game->mlx, "imgs/cloud2.xpm", &width, &height);

    game->img_floor = mlx_xpm_file_to_image(game->mlx, "imgs/blue.xpm", &width, &height);

    game->img_player = mlx_xpm_file_to_image(game->mlx, "imgs/plane.xpm", &width, &height);

    game->img_collect = mlx_xpm_file_to_image(game->mlx, "imgs/bomb.xpm", &width, &height);
	
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "imgs/planecarrier.xpm", &width, &height);
}
