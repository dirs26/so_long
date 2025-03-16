/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:36:03 by diegrod2          #+#    #+#             */
/*   Updated: 2025/03/15 21:40:15 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	sz_src;

	i = 0;
	sz_src = ft_strlen((char *)src);
	if (size == 0)
		return (sz_src);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (sz_src);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s) + 1;
	str = (char *)malloc(len);
	if (str != NULL)
		ft_strlcpy(str, s, len);
	return (str);
}