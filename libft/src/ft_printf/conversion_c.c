/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:44:18 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 11:34:56 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_stringl	*convert_c(t_conversion *conversion, va_list args)
{
	t_stringl	*output;

	if (conversion->specifier == 'C' || conversion->length == L)
	{
		output = str_to_stringl(convert_wchar((wchar_t)va_arg(args, wint_t)));
		if (output && output->length == 0)
		{
			ft_strdel(&(output->text));
			output->text = ft_strnew(1);
			output->length = 1;
		}
	}
	else
	{
		if ((output = str_to_stringl(ft_strnew(1))))
		{
			output->length = 1;
			*(output->text) = (unsigned char)va_arg(args, int);
		}
	}
	output = handle_zero_stringl(conversion, output);
	output = handle_width_stringl(conversion, output);
	return (output);
}
