/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:42:13 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/17 14:50:41 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	fill_catalogue1(t_specifier catalogue[15])
{
	catalogue[0].spec = '%';
	catalogue[0].function = convert_percent;
	catalogue[1].spec = 'i';
	catalogue[1].function = convert_di;
	catalogue[2].spec = 'd';
	catalogue[2].function = convert_di;
	catalogue[3].spec = 'D';
	catalogue[3].function = convert_di;
	catalogue[4].spec = 'u';
	catalogue[4].function = convert_u;
	catalogue[5].spec = 'U';
	catalogue[5].function = convert_u;
	catalogue[6].spec = 'o';
	catalogue[6].function = convert_o;
	catalogue[7].spec = 'O';
	catalogue[7].function = convert_o;
	catalogue[8].spec = 'x';
	catalogue[8].function = convert_x;
	catalogue[9].spec = 'X';
	catalogue[9].function = convert_x;
	catalogue[10].spec = 'p';
	catalogue[10].function = convert_p;
}

static void	fill_catalogue2(t_specifier catalogue[15])
{
	catalogue[11].spec = 'c';
	catalogue[11].function = convert_c;
	catalogue[12].spec = 'C';
	catalogue[12].function = convert_c;
	catalogue[13].spec = 's';
	catalogue[13].function = convert_s;
	catalogue[14].spec = 'S';
	catalogue[14].function = convert_s;
	catalogue[15].spec = 'b';
	catalogue[15].function = convert_b;
}

const char	*parse_percent(const char *format, t_stringl **substr, va_list args)
{
	t_conversion	conversion;
	t_specifier		catalogue[16];
	int				i;
	const char		*ptr;

	ptr = format;
	ft_bzero(&conversion, sizeof(conversion));
	ptr = parse_flags(ptr, &conversion);
	ptr = parse_width_precision(ptr, &conversion, args);
	ptr = parse_length(ptr, &conversion);
	ptr = parse_specifier(ptr, &conversion);
	fill_catalogue1(catalogue);
	fill_catalogue2(catalogue);
	i = -1;
	while (ptr && ++i < 16)
	{
		if (catalogue[i].spec == conversion.specifier)
		{
			*substr = catalogue[i].function(&conversion, args);
			return (ptr);
		}
	}
	if (ptr)
		*substr = convert_undefined(&conversion);
	return (ptr);
}

const char	*parse_character(const char *format, t_stringl *output,
							va_list args)
{
	t_stringl *substr;

	substr = NULL;
	if (*format == '%')
	{
		format++;
		format = parse_percent(format, &substr, args);
		if (format == NULL || substr == NULL || substr->length == -1)
			return (NULL);
		output = append_stringl(output, substr);
	}
	else
	{
		output = stringlappend_char(output, *format);
		format++;
	}
	return (format);
}
