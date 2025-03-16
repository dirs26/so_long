/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:22:07 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/15 23:48:35 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_items(t_game *game)
{
	if (game->count_coins == 0)
		error_item(game);
	if (game->count_exit == 0 || game->count_exit > 1)
		error_item(game);
	if (game->count_player == 0 || game->count_player > 1)
		error_item(game);
}

void	put_img_and_count(char item, t_game *game, int i, int j)
{
	if (item == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, j * 64, i
			* 64);
	else if (item == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, j * 64,
			i * 64);
	else if (item == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j * 64, i
			* 64);
	else if (item == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collect, j * 64, i
			* 64);
	else if (item == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, j * 64, i
			* 64);
}

void	put_img(char item, t_game *game, int i, int j)
{
	if (item == 'P')
	{
		game->pos_x = j * 64;
		game->pos_y = i * 64;
		game->count_player++;
	}
	else if (item == 'C')
		game->count_coins++;
	else if (item == 'E')
		game->count_exit++;
	else if (item != '0' && item != '1' && item != 'E' && item != 'C'
		&& item != 'P')
		error_item(game);
	put_img_and_count(item, game, i, j);
}

void	place_textures(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->columns)
		{
			put_img(game->map[i][j], game, i, j);
			j++;
		}
		i++;
	}
	check_items(game);
}
