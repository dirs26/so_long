/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:20:21 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/16 00:19:27 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(void)
{
	ft_printf("Error opening file");
	exit(EXIT_FAILURE);
}

void	load_map(char *argv, t_game *game)
{
	int		fd;
	char	*line;
	char	**file_map;

	game->rows = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_map();
	line = get_next_line(fd);
	if (!line)
		error_map();
	game->columns = (int)(ft_strlen(line) - 1);
	file_map = (char **)malloc(sizeof(char *) * 50);
	if (!file_map)
		error_map();
	while (line != NULL)
	{
		file_map[game->rows] = ft_strdup(line);
		free(line);
		game->rows++;
		line = get_next_line(fd);
	}
	file_map[game->rows] = NULL;
	game->map = file_map;
	close(fd);
}
