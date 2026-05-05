/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:06:20 by jduque-n          #+#    #+#             */
/*   Updated: 2026/05/02 15:34:51 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>   // Required for va_list, va_start, va_arg, va_end

int	sum_all(int count, ...)
{
	va_list	args;			/* 1. Declare the argument list */
	va_start(args, count);	/* 2. Initialize it — anchor to 'count' */
	int	total = 0;
	int	i = 0;

	while (i < count)
	{
		total += va_arg(args, int);
		i++; // 3. Pull the next argument as an int
	}

	va_end(args); // 4. Clean up
	return (total);
}

int	main(void)
{
	printf("%d\n", sum_all(3, 10, 20, 30));    // 60
	printf("%d\n", sum_all(5, 1, 2, 3, 4, 5)); // 15
	return (0);
}
