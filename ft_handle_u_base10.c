/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u_base10.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:07:57 by jduque-n          #+#    #+#             */
/*   Updated: 2026/05/07 16:34:45 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_unsigned(unsigned int nb)
{
	char	letter;

	letter = nb % 10 + '0';
	if (nb >= 10)
		return (ft_putnbr_unsigned(nb / 10) + write(1, &letter, 1));
	return (write(1, &letter, 1));
}

int	ft_handle_u_base10(unsigned int number)
{
	return (ft_putnbr_unsigned(number));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		returned;

// 	returned = ft_handle_u_base10(-1);
// 	printf("\nReturned : %d\n", returned);
// 	returned = ft_handle_u_base10(1);
// 	printf("\nReturned : %d\n", returned);
// 	returned = ft_handle_u_base10(-2147483647);
// 	printf("\nReturned : %d\n", returned);
// 	returned = ft_handle_u_base10(4294967295);
// 	printf("\nReturned : %d\n", returned);
// 	return (0);
// }
