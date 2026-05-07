/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:40:28 by jduque-n          #+#    #+#             */
/*   Updated: 2026/05/07 16:32:30 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	const char	*start;

	start = str;
	while (*str)
		str++;
	return (str - start);
}

int	ft_handle_s(char *string)
{
	int	str_size;

	if (!string)
		return (write(1, "(null)", 6));
	str_size = ft_strlen(string);
	return (write(1, string, str_size));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		returned;
// 	char	*string_null = 0;

// 	returned = ft_handle_s(string_null);
// 	printf("\nReturned : %d\n", returned);
// 	returned = ft_handle_s("This function is big");
// 	printf("\nReturned : %d\n", returned);
// 	return (0);
// }
