/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:33:37 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/05/25 21:58:11 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "format_options_bonus.h"
# include "format_linked_list_bonus.h"
# include "print_args_bonus.h"
# include "../libft/libft.h"

int				ft_printf(const char *format, ...);

#endif	// FT_PRINTF_BONUS_H