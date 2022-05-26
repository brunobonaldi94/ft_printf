/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_options.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:48:37 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/05/24 21:24:29 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_OPTIONS_H
# define FORMAT_OPTIONS_H

typedef struct s_format_opt
{
	char					specifier;
	char					*format_template;
	int						is_valid;
	struct s_format_opt		*next_format;
}	t_format_opt;

int		find_format_template(const char **format_template, char **format_start,
			int *numbers_bytes_printed, t_format_opt *format_opt);
int		add_format_specifier(const char **format_template,
			t_format_opt **format_opt);
void	add_format_template_start(const char *format_start,
			t_format_opt **format_opt);
int		is_specifier(char c);
int		has_invalid_specifier(const char *format_template,
			t_format_opt **format_opt);
int		is_valid_format(const char *specifier, t_format_opt **format_opt);
#endif //FORMAT_OPTIONS_H