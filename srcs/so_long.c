/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:00:21 by diegrod2          #+#    #+#             */
/*   Updated: 2025/02/24 11:00:21 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

typedef struct s_game {
    void    *mlx;
    void    *win;
    void    *img_wall;
    void    *img_floor;
    void    *img_player;
    void    *img_collect;
    void    *img_exit;
    int     tile_size;
    char    **map;
} t_game;

void load_images(t_game *game)
{
    int width;
    int height;

    game->img_wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &width, &height);
    game->img_floor = mlx_xpm_file_to_image(game->mlx, "floor.xpm", &width, &height);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "../imgs/PLYR.xpm", &width, &height);
    game->img_collect = mlx_xpm_file_to_image(game->mlx, "collect.xpm", &width, &height);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, "exit.xpm", &width, &height);
}

void render_map(t_game *game)
{
    int x, y;

    for (y = 0; game->map[y]; y++)
    {
        for (x = 0; game->map[y][x]; x++)
        {
            void *img = game->img_floor;
            if (game->map[y][x] == '1')
                img = game->img_wall;
            else if (game->map[y][x] == 'P')
                img = game->img_player;
            else if (game->map[y][x] == 'C')
                img = game->img_collect;
            else if (game->map[y][x] == 'E')
                img = game->img_exit;
            
            mlx_put_image_to_window(game->mlx, game->win, img, x * game->tile_size, y * game->tile_size);
        }
    }
}
