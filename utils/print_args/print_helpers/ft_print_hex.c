/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:10:54 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/05/24 21:10:11 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(va_list list_args, char specifier,
	int *number_chars_printed)
{
	unsigned int	hex_arg;
	size_t			hex_str_len;
	char			*hex_str;

	hex_arg = va_arg(list_args, unsigned int);
	hex_str = ft_itoa_base(hex_arg, 16, specifier);
	ft_putstr_fd(hex_str, 1);
	hex_str_len = ft_strlen(hex_str);
	(*number_chars_printed) += hex_str_len;
	free(hex_str);
}
