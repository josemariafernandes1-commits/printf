/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:00:21 by jduque-n          #+#    #+#             */
/*   Updated: 2026/05/07 17:00:37 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_hex(long nb, char *base)
{
	char	fin;

	fin = base[nb % 16];
	if (nb >= 16)
		return (ft_putnbr_hex(nb / 16, base) + write(1, &fin, 1));
	return (write(1, &fin, 1));
}

int	ft_handle_hex(unsigned int hex_number, char caps_lock)
{
	char	*upper_hex_base;
	char	*lower_hex_base;
	char	*base_chosen;

	upper_hex_base = "0123456789ABCDEF";
	lower_hex_base = "0123456789abcdef";
	if (caps_lock)
		base_chosen = upper_hex_base;
	else
		base_chosen = lower_hex_base;
	return (ft_putnbr_hex(hex_number, base_chosen));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	returned;

// 	returned = ft_handle_hex(4294967295, 1);
// 	printf("\nReturned : %d\n", returned);
// 	returned = ft_handle_hex(4294967295, 0);
// 	printf("\nReturned : %d\n", returned);
// 	return (0);
// }
