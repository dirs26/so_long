/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 04:29:01 by diegrod2          #+#    #+#             */
/*   Updated: 2024/10/23 20:18:57 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*mem;

	len = ft_strlen(s1) + ft_strlen(s2);
	mem = (char *)malloc(len + 1);
	if (mem == NULL)
		return (NULL);
	ft_strlcpy(mem, s1, ft_strlen(s1) + 1);
	ft_strlcat(mem, s2, len + 1);
	return (mem);
}
