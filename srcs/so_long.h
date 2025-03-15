/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:00:08 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/15 18:24:17 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game {
    void *mlx;
    void *win;
	void *exit;
    void *img_wall;
    void *img_floor;
    void *img_player;
    void *img_collect;
    void *img_exit;
    char **map;
	int		columns;
	int		rows;
    int tile_size;
} t_game;

void	render_map(t_game *game);
void	load_map(char *argv, t_game *game);
void	load_images(t_game *game);
void	clean_up_all(t_game *vars);
int	exit_win(t_game *vars);
int	main();

#endif