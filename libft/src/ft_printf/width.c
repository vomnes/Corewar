/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:47:48 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 12:06:27 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*handle_width(t_conversion *conversion, char *output)
{
	while (output && (int)ft_strlen(output) < conversion->width)
	{
		if (conversion->flag_minus)
			output = ft_strappend_char(output, ' ');
		else
			output = ft_strappend_char_before(output, ' ');
	}
	return (output);
}

t_stringl	*handle_width_stringl(t_conversion *conversion, t_stringl *output)
{
	while (output && output->text && (int)output->length < conversion->width)
	{
		if (conversion->flag_minus)
			output = stringlappend_char(output, ' ');
		else
			output = stringlappend_char_before(output, ' ');
	}
	return (output);
}
