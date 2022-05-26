/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 06:20:48 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/05/24 21:53:08 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_nbr_elements(size_t n, int base)
{
	int	itoa_elements;

	itoa_elements = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		itoa_elements++;
		n /= base;
	}
	return (itoa_elements);
}

char	should_uppercase_hex(char specifier, char value)
{
	if (specifier == 'X')
		return (ft_toupper(value));
	return (value);
}

char	*ft_itoa_base(unsigned long int n, int base, char specifier)
{
	char		*itoa;
	int			itoa_elements;
	static char	hex_base[16] = "0123456789abcdef";

	itoa_elements = get_nbr_elements(n, base);
	itoa = (char *)malloc(sizeof(char) * (itoa_elements + 1));
	if (!itoa)
		return (NULL);
	itoa[itoa_elements] = '\0';
	while (itoa_elements)
	{
		itoa[itoa_elements - 1] = should_uppercase_hex(specifier,
				hex_base[n % base]);
		n /= base;
		itoa_elements--;
	}
	return (itoa);
}
