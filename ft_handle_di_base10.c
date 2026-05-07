/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_di_base10.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:12:45 by jduque-n          #+#    #+#             */
/*   Updated: 2026/05/07 16:22:08 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(int nb)
{
	char	letter;

	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
		return (write(1, "-", 1) + ft_putnbr(-nb));
	letter = nb % 10 + '0';
	if (nb >= 10)
		return (ft_putnbr(nb / 10) + write(1, &letter, 1));
	return (write(1, &letter, 1));
}

int	ft_handle_di_base10(int number)
{
	return (ft_putnbr(number));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	returned;

// 	returned = ft_handle_di_base10(-2147483648);
// 	printf("\nReturned : %d\n", returned);
// 	returned = ft_handle_di_base10(2147483647);
// 	printf("\nReturned : %d\n", returned);
// 	return (0);
// }
