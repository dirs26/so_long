/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:52:35 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/16 00:29:00 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_w(t_game *game)
{
	print_moves(game);
	if (game->map[(game->pos_y / 64) - 1][game->pos_x / 64] != '1')
	{
		if (game->map[(game->pos_y / 64) - 1][game->pos_x / 64] == 'E'
			&& game->count_coins == 0)
			error_moves(game);
		else if (game->map[(game->pos_y / 64) - 1][game->pos_x / 64] != 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
				game->pos_x, game->pos_y);
			game->pos_y -= 64;
			mlx_put_image_to_window(game->mlx, game->win, game->img_player,
				game->pos_x, game->pos_y);
		}
	}
	if (game->map[game->pos_y / 64][(game->pos_x / 64)] == 'C')
	{
		game->count_coins--;
		game->map[game->pos_y / 64][(game->pos_x / 64)] = '0';
	}
}

void	key_s(t_game *game)
{
	print_moves(game);
	if (game->map[(game->pos_y / 64) + 1][game->pos_x / 64] != '1')
	{
		if (game->map[(game->pos_y / 64) + 1][game->pos_x / 64] == 'E'
			&& game->count_coins == 0)
			error_moves(game);
		else if (game->map[(game->pos_y / 64) + 1][game->pos_x / 64] != 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
				game->pos_x, game->pos_y);
			game->pos_y += 64;
			mlx_put_image_to_window(game->mlx, game->win, game->img_player,
				game->pos_x, game->pos_y);
		}
	}
	if (game->map[game->pos_y / 64][(game->pos_x / 64)] == 'C')
	{
		game->count_coins--;
		game->map[game->pos_y / 64][(game->pos_x / 64)] = '0';
	}
}

void	key_a(t_game *game)
{
	print_moves(game);
	if (game->map[game->pos_y / 64][(game->pos_x / 64) - 1] != '1')
	{
		if (game->map[game->pos_y / 64][(game->pos_x / 64) - 1] == 'E'
			&& game->count_coins == 0)
			error_moves(game);
		else if (game->map[game->pos_y / 64][(game->pos_x / 64) - 1] != 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
				game->pos_x, game->pos_y);
			game->pos_x -= 64;
			mlx_put_image_to_window(game->mlx, game->win, game->img_player,
				game->pos_x, game->pos_y);
		}
	}
	if (game->map[game->pos_y / 64][(game->pos_x / 64)] == 'C')
	{
		game->count_coins--;
		game->map[game->pos_y / 64][(game->pos_x / 64)] = '0';
	}
}

void	key_d(t_game *game)
{
	print_moves(game);
	if (game->map[game->pos_y / 64][(game->pos_x / 64) + 1] != '1')
	{
		if (game->map[game->pos_y / 64][(game->pos_x / 64) + 1] == 'E'
			&& game->count_coins == 0)
			error_moves(game);
		else if (game->map[game->pos_y / 64][(game->pos_x / 64) + 1] != 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
				game->pos_x, game->pos_y);
			game->pos_x += 64;
			if (game->moves % 2 == 0)
				mlx_put_image_to_window(game->mlx, game->win, game->player_move,
					game->pos_x, game->pos_y);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->img_player,
					game->pos_x, game->pos_y);
			game->moves++;
		}
	}
	if (game->map[game->pos_y / 64][(game->pos_x / 64)] == 'C')
	{
		game->count_coins--;
		game->map[game->pos_y / 64][(game->pos_x / 64)] = '0';
	}
}

int	loop(int keycode, t_game *game)
{
	if (keycode == 65307)
		error_moves(game);
	else if (keycode == 119 || keycode == 65362)
		key_w(game);
	else if (keycode == 115 || keycode == 65364)
		key_s(game);
	else if (keycode == 97 || keycode == 65361)
		key_a(game);
	else if (keycode == 100 || keycode == 65363)
		key_d(game);
	return (0);
}