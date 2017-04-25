/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:46:15 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/17 14:49:36 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_stringl	output;
	int			ret_value;

	output.text = ft_strnew(0);
	output.length = 0;
	va_start(args, format);
	while (format && *format)
		format = parse_character(format, &output, args);
	va_end(args);
	if (format == NULL || output.text == NULL || output.length == -1)
		ret_value = -1;
	else
	{
		ret_value = output.length;
		ret_value = write(1, output.text, ret_value);
	}
	free(output.text);
	return (ret_value);
}

int			ft_asprintf(char **ret, const char *format, ...)
{
	va_list		args;
	t_stringl	output;

	output.text = ft_strnew(0);
	output.length = 0;
	va_start(args, format);
	while (format && *format)
		format = parse_character(format, &output, args);
	va_end(args);
	if (format == NULL || output.text == NULL || output.length == -1)
		return (-1);
	*ret = output.text;
	return (output.length);
}
