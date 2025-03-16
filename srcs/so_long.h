/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:00:08 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/16 00:18:57 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../mlx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_game 
{
    void	*mlx;
    void	*win;
	void	*exit;
    void	*img_wall;
    void	*img_floor;
    void	*img_player;
    void	*img_collect;
    void	*img_exit;
	void	*player_move;
    char	**map;
	int		count_coins;
	int		count_moves;
	int		count_exit;
	int		count_player;
	int		columns;
	int		pos_x;
	int		pos_y;
	int		size_x;
	int		size_y;
	int		rows;
    int		tile_size;
	int		moves;
}			t_game;

void	render_map(t_game *game);
char	*ft_strdup(const char *s);
void	clean_up_all(t_game *game);
void	load_images(t_game *game);
void	load_map(char *argv, t_game *game);
int	loop(int keycode, t_game *game);
void	check_items(t_game *game);
void	check_file(char *file, size_t size);
int		walls(t_game *game);
void	check_map(int maps, char *map, t_game *game);
void	error_item(t_game *game);
void	put_img_and_count(char item, t_game *game, int i, int j);
void	put_img(char item, t_game *game, int i, int j);
void	place_textures(t_game *game);
void	start_count(t_game *game);
void	error_moves(t_game *game);
void	print_moves(t_game *game);
int	exit_win(t_game *game);
int	main();

#endif