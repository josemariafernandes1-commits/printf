/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mixed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:32:13 by jduque-n          #+#    #+#             */
/*   Updated: 2026/05/05 14:00:35 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <string.h>

void	print_mixed(char *mixed_string, ...)
{
	char	*spoken;
	int		counted;
	va_list	args;

	va_start (args, mixed_string)
	while(*mixed_string)
	{
		if (*mixed_string == 's')
		{
			spoken = va_arg(args, char *);
			write(1, spoken, strlen(spoken));
			write(1, '\n', 1);
		}
		else if (*mixed_string == 'd')
		{
			counted = va_arg(args, int);
			write (1, ft_putnbr(counted), 1);
		}	
	}
	va_end(args);
	return ;
}

int	main(void)
{
	print_mixed(3, "hello", "world", "42");
	return (0);
}
