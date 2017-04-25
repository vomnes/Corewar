/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:44:40 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 11:35:57 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*uintmaxtoa_octal(uintmax_t number)
{
	char *output;

	output = ft_strnew(0);
	while (output && number / 8 != 0)
	{
		output = ft_strappend_char_before(output, number % 8 + '0');
		number = number / 8;
	}
	output = ft_strappend_char_before(output, number % 8 + '0');
	return (output);
}

t_stringl	*convert_o(t_conversion *conversion, va_list args)
{
	uintmax_t	number;
	char		*output;

	if (conversion->specifier == 'O')
		conversion->length = L;
	number = handle_length_unsigned(conversion, args);
	output = uintmaxtoa_octal(number);
	output = handle_precision_numeric(conversion, output);
	output = handle_sharp_o(conversion, output);
	output = handle_zero(conversion, output);
	output = handle_width(conversion, output);
	return (str_to_stringl(output));
}
