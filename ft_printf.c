/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:14:48 by jduque-n          #+#    #+#             */
/*   Updated: 2026/05/07 16:44:17 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dispatch_helpers(const char *format, va_list args)
{
	if (*format == '%')
		return (write (1, "%", 1));
	else if (*format == 'c')
		return (ft_handle_c(va_arg(args, int)));
	else if (*format == 's')
		return (ft_handle_s(va_arg(args, char *)));
	else if (*format == 'p')
		return (ft_handle_void_hex(va_arg(args, void *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_handle_di_base10(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_handle_u_base10(va_arg(args, unsigned int)));
	else if (*format == 'x')
		return (ft_handle_hex(va_arg(args, unsigned int), 0));
	else if (*format == 'X')
		return (ft_handle_hex(va_arg(args, unsigned int), 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		check;

	check = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) != '\0')
			{
				check += ft_dispatch_helpers(format + 1, args);
				format++;
			}
		}
		else
			check += write (1, format, 1);
		format++;
	}
	va_end(args);
	return (check);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		returned;

// 	returned = ft_printf("%i", 123345);
// 	ft_printf("\nReturned : %d\n", returned);
// 	return (0);
// }
