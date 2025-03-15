/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:20:21 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/15 17:20:42 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

# define TILE_SIZE 64


char **load_map(char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening map file");
        return NULL;
    }

    char **map = malloc(sizeof(char *) * 10);
    if (!map)
    {
        perror("Error allocating memory for map");
        close(fd);
        return NULL;
    }

    char *line;
    int i = 0;
    int map_size = 10;  // Initial map size
    while ((line = get_next_line(fd)) != NULL)
    {
        if (i >= map_size)
        {
            map = realloc(map, sizeof(char *) * map_size);
            if (!map)
            {
                perror("Error reallocating memory for map");
                close(fd);
                return NULL;
            }
        }

        map[i] = line;
        i++;
    }

    map[i] = NULL;
    close(fd);
    return map;
}
