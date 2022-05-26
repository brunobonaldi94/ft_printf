/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 03:40:02 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/05/24 21:12:08 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ARGS_H
# define PRINT_ARGS_H

int			print_args(t_format_opt **format_opt, va_list list_args);
char		*ft_itoa_base(unsigned long int n, int base, char specifier);
void		ft_print_char(va_list list_args, int *number_chars_printed);
void		ft_print_str(va_list list_args, int *number_chars_printed);
void		ft_print_int(va_list list_args, int *number_chars_printed);
void		ft_print_uint(va_list list_args, char specifier,
				int *number_chars_printed);
void		ft_print_ptr(va_list list_args, char specifier,
				int *number_chars_printed);
void		ft_print_percent(int *number_chars_printed);
void		ft_print_hex(va_list list_args, char specifier,
				int *number_chars_printed);

#endif //PRINT_ARGS_H