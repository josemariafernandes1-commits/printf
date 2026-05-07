/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 19:04:50 by jduque-n          #+#    #+#             */
/*   Updated: 2026/05/07 16:13:43 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

int	ft_printf(const char *format, ...);
int	ft_handle_c(int character);
int	ft_handle_di_base10(int number);
int	ft_handle_hex(unsigned int hex_number, char caps_lock);
int	ft_handle_s(char *string);
int	ft_handle_u_base10(unsigned int number);
int	ft_handle_void_hex(void *pointer);

#endif