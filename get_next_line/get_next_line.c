/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:47:20 by diegrod2          #+#    #+#             */
/*   Updated: 2024/11/21 11:47:20 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_from_file(char *basin_buffer, int fd)
{
	char	*buffer;
	int		size;

	size = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!mod_strchr(basin_buffer, '\n') && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(basin_buffer);
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		basin_buffer = mod_strjoin(basin_buffer, buffer);
	}
	free(buffer);
	return (basin_buffer);
}

char	*extract_line(char *basin_buffer)
{
	char	*s;
	int		i;

	i = 0;
	if (!basin_buffer[i])
		return (NULL);
	while (basin_buffer[i] != '\0' && basin_buffer[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (basin_buffer[i] != '\0' && basin_buffer[i] != '\n')
	{
		s[i] = basin_buffer[i];
		i++;
	}
	if (basin_buffer[i] == '\n')
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*obtain_remaining(char *basin_buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (basin_buffer[i] != '\0' && basin_buffer[i] != '\n')
		i++;
	if (basin_buffer[i] == '\0')
	{
		free(basin_buffer);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(basin_buffer) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (basin_buffer[i] != '\0')
		str[j++] = basin_buffer[i++];
	str[j] = '\0';
	free(basin_buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	basin_buffer = read_from_file(basin_buffer, fd);
	if (!basin_buffer)
		return (NULL);
	line = extract_line(basin_buffer);
	basin_buffer = obtain_remaining(basin_buffer);
	return (line);
}
