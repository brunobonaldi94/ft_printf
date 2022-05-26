/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:39:55 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/05/24 21:10:19 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(va_list list_args, int *number_chars_printed)
{
	int		int_arg;
	char	*int_str;
	size_t	int_str_len;

	int_arg = va_arg(list_args, int);
	int_str = ft_itoa(int_arg);
	ft_putstr_fd(int_str, 1);
	int_str_len = ft_strlen(int_str);
	(*number_chars_printed) += int_str_len;
	free(int_str);
}
