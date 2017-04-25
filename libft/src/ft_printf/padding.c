/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:46:47 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 14:08:59 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*handle_zero(t_conversion *conversion, char *output)
{
	int		extra_characters;

	if (output)
	{
		if (conversion->period && ft_strchr("dDioOuUxXb",
			conversion->specifier))
			return (output);
		if (ft_strchr("xX", conversion->specifier) && conversion->flag_sharp)
			extra_characters = 2;
		else
			extra_characters = 0;
		while (conversion->flag_zero && !conversion->flag_minus &&
				(int)ft_strlen(output) < conversion->width - extra_characters)
			output = ft_strappend_char_before(output, '0');
	}
	return (output);
}

t_stringl	*handle_zero_stringl(t_conversion *conversion, t_stringl *output)
{
	while (output && output->text && conversion->flag_zero &&
		!conversion->flag_minus && output->length < conversion->width)
	{
		output->text = ft_strappend_char_before(output->text, '0');
		output->length += 1;
	}
	return (output);
}

char		*handle_zero_plus_space(t_conversion *conversion, char *output)
{
	int		sign;
	int		negative;

	if (output && (conversion->flag_plus || conversion->flag_space ||
		*output == '-'))
		sign = 1;
	else
		sign = 0;
	if (output && *output == '-')
	{
		negative = 1;
		output = ft_strchop_before(output, 1);
	}
	else
		negative = 0;
	while (output && conversion->flag_zero && !conversion->flag_minus &&
	!conversion->period && (int)ft_strlen(output) < conversion->width - sign)
		output = ft_strappend_char_before(output, '0');
	if (output && negative)
		output = ft_strappend_char_before(output, '-');
	else if (output && conversion->flag_plus)
		output = ft_strappend_char_before(output, '+');
	else if (output && conversion->flag_space)
		output = ft_strappend_char_before(output, ' ');
	return (output);
}
