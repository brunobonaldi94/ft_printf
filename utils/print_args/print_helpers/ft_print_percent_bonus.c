/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 02:07:58 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/05/24 22:21:13 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_percent(int *number_chars_printed)
{
	ft_putchar_fd('%', 1);
	(*number_chars_printed) += 1;
}
