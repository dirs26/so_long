/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putunbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:01:07 by diegrod2          #+#    #+#             */
/*   Updated: 2024/10/31 17:01:07 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int		len;
	char	num;

	len = 0;
	if (n >= 10)
		len += ft_putunbr(n / 10);
	num = n % 10 + '0';
	len += ft_putchar(num);
	return (len);
}
