/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_options_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 04:09:47 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/05/24 20:11:49 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_format_specifier(const char **format_template,
	t_format_opt **format_opt)
{
	const char	*specifier;
	int			found;

	specifier = *format_template;
	found = 0;
	if (is_specifier(*specifier))
	{
		(*format_opt)->specifier = *specifier;
		specifier++;
		found = 1;
	}
	if (found == 0)
		(*format_opt)->is_valid = 0;
	*format_template = specifier;
	return (found);
}

void	add_format_template_start(const char *format_start,
			t_format_opt **format_opt)
{
	const char	*found_percentage;
	size_t		format_len;

	found_percentage = ft_strchr(format_start, '%');
	if (!found_percentage)
		found_percentage = format_start + ft_strlen(format_start);
	format_len = found_percentage - (--format_start);
	(*format_opt)->format_template = ft_substr(format_start, 0, format_len);
}
