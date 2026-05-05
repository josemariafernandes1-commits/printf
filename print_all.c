/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:29:47 by jduque-n          #+#    #+#             */
/*   Updated: 2026/05/02 16:46:37 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

void	print_all(int count, ...)
{
	char	*spoken;
	int		i;
	va_list	args;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		spoken = va_arg(args, char *);
		write(1, spoken, strlen(spoken));
		write(1, "\n", 1);
		i++;
	}
	va_end(args);
	return ;
}

int	main(void)
{
	print_all(3, "hello", "world", "42");
	return (0);
}
