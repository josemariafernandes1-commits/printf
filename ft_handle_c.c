/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:10:36 by jduque-n          #+#    #+#             */
/*   Updated: 2026/05/07 16:19:03 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_c(int character)
{
	return (write(1, &character, 1));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	returned;

// 	returned = ft_handle_c('\n');
// 	printf("\nReturned : %d\n", returned);
// 	return (0);
// }
