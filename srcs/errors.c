/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:14:22 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/15 23:14:20 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_game *game)
{
	game->count_moves++;
	ft_printf("\033[0;32mLlevas: %d movimientos\033[0m\n", game->count_moves);
}

void	error_item(t_game *game)
{
	ft_printf("\033[0;31mEl mapa no contiene items validos\033[0m");
	clean_up_all(game);
	exit(EXIT_FAILURE);
}

void	error_moves(t_game *game)
{
	clean_up_all(game);
	exit(EXIT_FAILURE);
}