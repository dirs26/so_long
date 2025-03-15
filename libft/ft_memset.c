/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:20:19 by diegrod2          #+#    #+#             */
/*   Updated: 2024/10/23 20:19:36 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*st;

	st = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		st[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
