/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:01:28 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/05/24 21:10:46 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(va_list list_args, int *number_chars_printed)
{
	char	*str_arg;
	int		should_free;

	str_arg = va_arg(list_args, char *);
	should_free = 0;
	if (str_arg == NULL)
	{
		str_arg = ft_strdup("(null)");
		should_free = 1;
	}
	ft_putstr_fd(str_arg, 1);
	(*number_chars_printed) += ft_strlen(str_arg);
	if (should_free)
		free(str_arg);
}
