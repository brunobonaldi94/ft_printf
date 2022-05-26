/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:02:38 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/05/24 21:11:07 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_uint(va_list list_args, char specifier,
			int *number_chars_printed)
{
	unsigned int		uint_arg;
	char				*uint_str;
	size_t				uint_str_len;

	uint_arg = va_arg(list_args, unsigned int);
	uint_str = ft_itoa_base(uint_arg, 10, specifier);
	ft_putstr_fd(uint_str, 1);
	uint_str_len = ft_strlen(uint_str);
	(*number_chars_printed) += uint_str_len;
	free(uint_str);
}
