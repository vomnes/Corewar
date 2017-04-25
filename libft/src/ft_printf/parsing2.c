/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:46:54 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/30 12:10:07 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*parse_flags(const char *ptr, t_conversion *conversion)
{
	while (ptr && ft_strchr("-+ #0", *ptr) && *ptr)
	{
		if (*ptr == '-')
			conversion->flag_minus = 1;
		else if (*ptr == '+')
			conversion->flag_plus = 1;
		else if (*ptr == ' ')
			conversion->flag_space = 1;
		else if (*ptr == '#')
			conversion->flag_sharp = 1;
		else if (*ptr == '0')
			conversion->flag_zero = 1;
		ptr++;
	}
	return (ptr);
}

const char	*width_precision_to_int(const char *ptr, int *value, va_list args)
{
	char	*number;

	if (ptr && *ptr == '*')
	{
		*value = va_arg(args, int);
		return (width_precision_to_int(ptr + 1, value, args));
	}
	else if (ptr && ft_isdigit(*ptr))
	{
		if (!(number = ft_strnew(0)))
			return (NULL);
		while (ft_isdigit(*ptr))
		{
			number = ft_strappend_char(number, *ptr);
			ptr++;
		}
		*value = ft_atoi(number);
		ft_strdel(&number);
		return (width_precision_to_int(ptr, value, args));
	}
	else
		return (ptr);
}

const char	*parse_width_precision(const char *ptr, t_conversion *conversion,
									va_list args)
{
	int	width_value;
	int precision_value;

	width_value = 0;
	precision_value = 0;
	ptr = width_precision_to_int(ptr, &width_value, args);
	if (width_value < 0)
	{
		conversion->flag_minus = 1;
		conversion->width = -width_value;
	}
	else
		conversion->width = width_value;
	if (ptr && *ptr == '.')
	{
		conversion->period = 1;
		ptr++;
		ptr = width_precision_to_int(ptr, &precision_value, args);
		if (precision_value < 0)
			conversion->period = 0;
		else
			conversion->precision = precision_value;
	}
	return (ptr);
}

const char	*parse_length(const char *ptr, t_conversion *conversion)
{
	if (ptr && *ptr == 'h' && *(ptr + 1) == 'h')
	{
		conversion->length = HH;
		return (ptr + 2);
	}
	else if (ptr && *ptr == 'l' && *(ptr + 1) == 'l')
	{
		conversion->length = LL;
		return (ptr + 2);
	}
	else if (ptr && (*ptr == 'h' || *ptr == 'l' || *ptr == 'j' || *ptr == 'z'))
	{
		if (*ptr == 'h')
			conversion->length = H;
		else if (*ptr == 'l')
			conversion->length = L;
		else if (*ptr == 'j')
			conversion->length = J;
		else if (*ptr == 'z')
			conversion->length = Z;
		return (ptr + 1);
	}
	else
		return (ptr);
}

const char	*parse_specifier(const char *ptr, t_conversion *conversion)
{
	if (ptr)
	{
		conversion->specifier = *ptr;
		if (*ptr)
			return (ptr + 1);
	}
	return (ptr);
}
