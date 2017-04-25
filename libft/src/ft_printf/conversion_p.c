/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:45:01 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/25 19:12:10 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_stringl	*convert_p(t_conversion *conversion, va_list args)
{
	uintmax_t	number;
	char		*output;

	number = (uintmax_t)va_arg(args, void *);
	output = uintmaxtoa_hexa(number, 'x');
	output = handle_precision_numeric(conversion, output);
	conversion->flag_sharp = 1;
	conversion->specifier = 'x';
	output = handle_zero(conversion, output);
	output = handle_sharp_x(conversion, output);
	output = handle_width(conversion, output);
	return (str_to_stringl(output));
}
