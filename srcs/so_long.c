/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:00:21 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/15 18:46:22 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define TILE_SIZE 64

int main(int argc, char *argv[])
{
    t_game game;

    if (argc != 2)
    {
        ft_printf("Usage: ./so_long map_file.ber\n");
        return (1);
    }
    game.mlx = mlx_init();
    if (!game.mlx)
    {
        ft_printf("Error: mlx_init failed\n");
        return (1);
    }
    load_map(argv[1], &game);
    load_images(&game);
    game.win = mlx_new_window(game.mlx, game.columns * game.tile_size, game.rows * game.tile_size, "So Long");
    if (!game.win)
    {
        ft_printf("Error: mlx_new_window failed\n");
        return (1);
    }
    render_map(&game);
    mlx_loop(game.mlx);
    return (0);
}
