/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_options_helpers_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:18:33 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/05/24 20:39:09 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_specifier(char c)
{
	return (c == 'c' || c == 's'
		|| c == 'p' || c == 'd'
		|| c == 'i' || c == 'u'
		|| c == 'x' || c == 'X'
		|| c == '%');
}

int	find_format_template(const char **format_template, char **format_start,
		int *numbers_bytes_printed, t_format_opt *format_opt)
{
	const char	*fmt_template;
	int			found;

	fmt_template = *format_template;
	found = 0;
	while (*fmt_template)
	{
		if (*fmt_template == '%')
		{
			*format_start = (char *)fmt_template;
			fmt_template++;
			found = 1;
			break ;
		}
		if (!format_opt || format_opt->is_valid)
			ft_putchar_fd(*fmt_template, 1);
		fmt_template++;
		(*numbers_bytes_printed) += 1;
	}
	*format_template = fmt_template;
	return (found);
}
