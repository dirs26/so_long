/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:06:49 by diegrod2          #+#    #+#             */
/*   Updated: 2024/11/07 13:06:49 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*mod_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*mod_strchr(const char *s, int c);

char	*get_next_line(int fd);
char	*read_from_file(char *basin_buffer, int fd);
char	*extract_line(char *basin_buffer);
char	*obtain_remaining(char *basin_buffer);

#endif