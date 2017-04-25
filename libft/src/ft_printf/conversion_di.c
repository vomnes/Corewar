/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:44:29 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/25 15:59:01 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_stringl	*convert_di(t_conversion *conversion, va_list args)
{
	char		*output;
	intmax_t	number;

	if (conversion->specifier == 'D')
		conversion->length = L;
	number = handle_length_decimal(conversion, args);
	output = ft_intmaxtoa(number);
	output = handle_precision_numeric(conversion, output);
	output = handle_zero_plus_space(conversion, output);
	output = handle_width(conversion, output);
	return (str_to_stringl(output));
}
