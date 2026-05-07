/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_void_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:56:54 by jduque-n          #+#    #+#             */
/*   Updated: 2026/05/07 17:02:42 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_hex(unsigned long nb, char *base)
{
	char	fin;

	fin = base[nb % 16];
	if (nb >= 16)
		return (ft_putnbr_hex(nb / 16, base) + write(1, &fin, 1));
	return (write(1, &fin, 1));
}

int	ft_handle_void_hex(void *pointer)
{
	unsigned long	pointer_mem_adress;
	char			*hex_base;
	int				returned;

	returned = 0;
	hex_base = "0123456789abcdef";
	pointer_mem_adress = (unsigned long)pointer;
	if (!pointer)
		return (write(1, "(nil)", 5));
	returned += write(1, "0x", 2);
	return (returned + ft_putnbr_hex(pointer_mem_adress, hex_base));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		returned;
// 	void	*string_nil = 0;
// 	void	*test_pointer = "Active";

// 	returned = ft_handle_void_hex(test_pointer);
// 	printf("\nReturned : %d\n", returned);
// 	returned = ft_handle_void_hex(string_nil);
// 	printf("\nReturned : %d\n", returned);
// 	return (0);
// }
