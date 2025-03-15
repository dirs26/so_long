/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:53:17 by diegrod2          #+#    #+#             */
/*   Updated: 2024/10/23 19:49:16 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	free_res(char **res, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	wrd;

	i = 0;
	wrd = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			wrd++;
		i++;
	}
	return (wrd);
}

static int	wrdlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**place_res(char const *s, char c, char **res)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count = wrdlen(&s[i], c);
			res[j] = (char *)malloc((count + 1) * sizeof(char));
			if (!res[j])
			{
				return (free_res(res, j), NULL);
			}
			count = 0;
			while (s[i] && s[i] != c)
				res[j][count++] = s[i++];
			res[j++][count] = '\0';
		}
	}
	return (res[j] = NULL, res);
}

char	**ft_split(char const *s, char c)
{
	int		wrd;
	char	**res;

	if (!s)
		return (NULL);
	wrd = count_words(s, c);
	res = (char **)malloc((wrd + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (place_res(s, c, res));
}
