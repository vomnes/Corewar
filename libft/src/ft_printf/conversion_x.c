/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:46:05 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 11:44:55 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		find_digit_hexa(uintmax_t number, char specifier)
{
	if (number <= 9)
		return ('0' + number);
	else
	{
		if (specifier == 'x')
			return ('a' + number - 10);
		else if (specifier == 'X')
			return ('A' + number - 10);
	}
	return ('$');
}

char		*uintmaxtoa_hexa(uintmax_t number, char specifier)
{
	char *output;

	output = ft_strnew(0);
	while (output && number / 16 != 0)
	{
		output = ft_strappend_char_before(output, find_digit_hexa(number % 16,
																specifier));
		number = number / 16;
	}
	output = ft_strappend_char_before(output, find_digit_hexa(number % 16,
															specifier));
	return (output);
}

t_stringl	*convert_x(t_conversion *conversion, va_list args)
{
	uintmax_t	number;
	char		*output;

	number = handle_length_unsigned(conversion, args);
	output = uintmaxtoa_hexa(number, conversion->specifier);
	output = handle_precision_numeric(conversion, output);
	output = handle_zero(conversion, output);
	if (number != 0)
		output = handle_sharp_x(conversion, output);
	output = handle_width(conversion, output);
	return (str_to_stringl(output));
}
