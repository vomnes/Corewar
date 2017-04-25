/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_uU.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:45:49 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/25 15:45:50 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	length_uintmax(uintmax_t nbr)
{
	int length;

	length = 0;
	if (nbr == 0)
		length++;
	while (nbr)
	{
		nbr = nbr / 10;
		length++;
	}
	return (length);
}

static char	*uintmaxtoa(uintmax_t number)
{
	char		*output;
	int			length;

	length = length_uintmax(number);
	if (!(output = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	output[length] = '\0';
	while (--length > -1)
	{
		output[length] = number % 10 + '0';
		number = number / 10;
	}
	return (output);
}

t_stringl	*convert_u(t_conversion *conversion, va_list args)
{
	uintmax_t	number;
	char		*output;

	if (conversion->specifier == 'U')
		conversion->length = L;
	number = handle_length_unsigned(conversion, args);
	output = uintmaxtoa(number);
	output = handle_precision_numeric(conversion, output);
	output = handle_zero(conversion, output);
	output = handle_width(conversion, output);
	return (str_to_stringl(output));
}
