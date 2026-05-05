/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:14:48 by jduque-n          #+#    #+#             */
/*   Updated: 2026/05/05 14:44:54 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

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
			if (*(format + 1) == '%')
			{
				check += write (1, "%", 1);
				format++;
			}
			else
				dispatch_to_helpers;
		}
		else
			check += write (1, format, 1);
		format++;
	}
	va_end(args);
	return (check);
}
