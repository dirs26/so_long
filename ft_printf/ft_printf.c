/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:37:52 by diegrod2          #+#    #+#             */
/*   Updated: 2024/11/05 12:37:52 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_print_str(va_list args, const char print_str)
{
	int		len;

	len = 0;
	if (print_str == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (print_str == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (print_str == 'd' || print_str == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (print_str == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (print_str == 'x' || print_str == 'X')
		len += ft_puthex(va_arg(args, unsigned int), print_str);
	else if (print_str == 'p')
		len += ft_putptr(va_arg(args, unsigned long *));
	else if (print_str == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(char const *print_str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, print_str);
	while (print_str[i])
	{
		if (print_str[i] == '%' && print_str[i + 1])
		{
			len += ft_print_str(args, print_str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(print_str[i]);
		i++;
	}
	va_end (args);
	return (len);
}
