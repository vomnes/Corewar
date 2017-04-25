/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_undefined.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:45:34 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 11:43:57 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_stringl	*convert_undefined(t_conversion *conversion)
{
	t_stringl	*output;

	if (conversion->specifier)
	{
		if ((output = str_to_stringl(ft_strnew(1))))
		{
			output->length = 1;
			(output->text)[0] = conversion->specifier;
		}
	}
	else
		output = str_to_stringl(ft_strnew(0));
	output = handle_zero_stringl(conversion, output);
	output = handle_width_stringl(conversion, output);
	return (output);
}
