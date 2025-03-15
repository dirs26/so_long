/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 04:28:36 by diegrod2          #+#    #+#             */
/*   Updated: 2024/10/23 19:50:36 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_counter(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n != 0)
	{
		if (n < 0)
		{
			count++;
			n = -n;
		}
		while (n != 0)
		{
			n = n / 10;
			count++;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	sz;
	char	*str;
	long	nbr;

	nbr = n;
	sz = ft_counter(n);
	str = malloc((sz + 1));
	if (!str)
		return (0);
	str[sz--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[sz--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
