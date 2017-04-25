/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:46:24 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/25 15:46:25 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t	handle_length_decimal(t_conversion *conversion, va_list args)
{
	if (conversion->length == HH)
		return ((intmax_t)(signed char)va_arg(args, int));
	else if (conversion->length == H)
		return ((intmax_t)(short)va_arg(args, int));
	else if (conversion->length == L)
		return ((intmax_t)va_arg(args, long));
	else if (conversion->length == LL)
		return ((intmax_t)va_arg(args, long long));
	else if (conversion->length == J)
		return (va_arg(args, intmax_t));
	else if (conversion->length == Z)
		return ((intmax_t)va_arg(args, ssize_t));
	else
		return ((intmax_t)va_arg(args, int));
}

uintmax_t	handle_length_unsigned(t_conversion *conversion, va_list args)
{
	if (conversion->length == HH)
		return ((uintmax_t)(unsigned char)va_arg(args, int));
	else if (conversion->length == H)
		return ((uintmax_t)(unsigned short)va_arg(args, int));
	else if (conversion->length == L)
		return ((uintmax_t)va_arg(args, unsigned long));
	else if (conversion->length == LL)
		return ((uintmax_t)va_arg(args, unsigned long long));
	else if (conversion->length == J)
		return (va_arg(args, uintmax_t));
	else if (conversion->length == Z)
		return ((uintmax_t)va_arg(args, size_t));
	else
		return ((uintmax_t)va_arg(args, unsigned int));
}
