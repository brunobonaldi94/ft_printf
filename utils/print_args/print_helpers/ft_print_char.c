/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:55:31 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/05/24 21:09:46 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list list_args, int *number_chars_printed)
{
	char	arg_char;

	arg_char = va_arg(list_args, int);
	ft_putchar_fd(arg_char, 1);
	(*number_chars_printed) += 1;
}
