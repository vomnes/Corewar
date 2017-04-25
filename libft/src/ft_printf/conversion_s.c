/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:45:24 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 11:42:18 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			how_many_bytes_in_utf8(char byte)
{
	if ((byte & 0x80) == 0)
		return (1);
	if ((byte & 0x20) == 0)
		return (2);
	if ((byte & 0x10) == 0)
		return (3);
	if ((byte & 0x8) == 0)
		return (4);
	return (0);
}

char		*truncate_string(t_conversion *conversion, char *input)
{
	char	*ptr;
	char	*wchar_beginning;
	int		i;

	if (!input)
		return (NULL);
	if (conversion->period && conversion->precision < (int)ft_strlen(input))
		input[conversion->precision] = 0;
	ptr = input;
	while (*ptr)
	{
		wchar_beginning = ptr;
		i = how_many_bytes_in_utf8(*ptr);
		while (i > 0 && *ptr)
		{
			i--;
			ptr++;
		}
	}
	if (i != 0 && *input)
		*wchar_beginning = '\0';
	return (input);
}

t_stringl	*convert_s(t_conversion *conversion, va_list args)
{
	const char	*raw_input;
	char		*input;

	input = NULL;
	if (conversion->length == L || conversion->specifier == 'S')
		input = convert_wstring(va_arg(args, wchar_t *));
	else
	{
		raw_input = va_arg(args, char *);
		if (raw_input)
		{
			if ((input = ft_strnew(ft_strlen(raw_input))))
				ft_strcat(input, raw_input);
		}
	}
	if (!input)
	{
		if ((input = ft_strnew(6)))
			ft_strcat(input, "(null)");
	}
	input = truncate_string(conversion, input);
	input = handle_zero(conversion, input);
	input = handle_width(conversion, input);
	return (str_to_stringl(input));
}
