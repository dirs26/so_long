/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:26:50 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/15 23:35:23 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_file(void)
{
	ft_printf("\033[0;31mEl mapa no es valido\033[0m");
	exit(EXIT_FAILURE);
}

void	check_file(char *file, size_t size)
{
	char	*type_file;
	int		i;
	int		j;

	type_file = ".ber";
	i = size;
	j = 0;
	if (size < 4)
		error_file();
	while (i > 0)
	{
		if (file[i] == '.')
			break ;
		i--;
	}
	if ((size - i) != 4)
		error_file();
	while (file[i] != '\0' && type_file[j] != '\0')
	{
		if (file[i] != type_file[j])
			error_file();
		i++;
		j++;
	}
}

int	walls(t_game *game)
{
	int	i;

	if (!game->map || game->rows <= 0 || game->columns <= 0)
		return (0);
	i = 0;
	while (i < game->columns)
	{
		if (game->map[0][i] != '1' || game->map[game->rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->rows)
	{
		if (game->map[i][0] != '1' || game->map[i][game->columns - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_map(int maps, char *map, t_game *game)
{
	int	size;

	if (maps != 2)
	{
		if (maps == 1)
			ft_printf("\033[0;31mError añade un mapa\033[0m");
		else
			ft_printf("\033[0;31mError añade un solo mapa\033[0m");
		exit(EXIT_FAILURE);
	}
	size = ft_strlen(map);
	check_file(map, size);
	load_map(map, game);
	if (!walls(game))
	{
		ft_printf("\033[0;31mError el mapa no esta cerrado por paredes\033[0m");
		exit(EXIT_FAILURE);
	}
}