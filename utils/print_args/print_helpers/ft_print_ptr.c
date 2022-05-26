/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:47:43 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/05/24 21:26:21 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(va_list list_args, char specifier,
			int *number_chars_printed)
{
	void				*ptr_arg;
	char				*ptr_str;
	size_t				ptr_str_len;
	char				*ptr_str_joined;

	ptr_arg = va_arg(list_args, void *);
	if (ptr_arg != NULL)
	{
		ptr_str = ft_itoa_base((unsigned long)ptr_arg, 16, specifier);
		ptr_str_joined = ft_strjoin("0x", ptr_str);
		free(ptr_str);
	}
	else
		ptr_str_joined = ft_strdup("(nil)");
	ft_putstr_fd(ptr_str_joined, 1);
	ptr_str_len = ft_strlen(ptr_str_joined);
	(*number_chars_printed) += (ptr_str_len);
	free(ptr_str_joined);
}
