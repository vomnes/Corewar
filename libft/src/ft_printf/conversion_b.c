/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:51:47 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 15:30:26 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			binary_length(uintmax_t number)
{
	int	count;

	count = 64;
	while (count > 0 && !(number & ((uintmax_t)1 << (count - 1))))
		count--;
	return (count);
}

char		*uintmaxtoa_binary(uintmax_t number)
{
	char	*output;
	int		length;
	int		i;

	length = binary_length(number);
	output = ft_strnew(length);
	i = 0;
	while (output && length > 0)
	{
		if (number & (uintmax_t)1 << i)
			output[length - 1] = '1';
		else
			output[length - 1] = '0';
		length--;
		i++;
	}
	return (output);
}

t_stringl	*convert_b(t_conversion *conversion, va_list args)
{
	uintmax_t	number;
	char		*output;

	number = handle_length_unsigned(conversion, args);
	output = uintmaxtoa_binary(number);
	output = handle_precision_numeric(conversion, output);
	output = handle_sharp_b(conversion, output);
	if (conversion->flag_sharp == 0)
		output = handle_zero(conversion, output);
	output = handle_width(conversion, output);
	return (str_to_stringl(output));
}
