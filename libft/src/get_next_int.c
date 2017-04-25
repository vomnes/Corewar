/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:52:43 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/08 19:26:39 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*handle_blanks_signs(char *str, int *negative, int *status)
{
	*negative = 0;
	while (*str == '\t' || *str == '\v' || *str == '\r' || *str == '\f' ||
			*str == '\n' || *str == ' ')
		str++;
	if (*str == '+')
	{
		*status = -1;
		str++;
	}
	else if (*str == '-')
	{
		*negative = 1;
		*status = -1;
		str++;
	}
	return (str);
}

static void	convert_digits(char **str, int *output, int negative, int *status)
{
	int count;

	count = 0;
	while (count < 9 && **str > 47 && **str < 58 && **str)
	{
		*status = 1;
		*output = *output * 10 + (**str - '0');
		count++;
		(*str)++;
	}
	if ((*output < 214748364 && (**str >= '0' && **str <= '9')) ||
			(*output == 214748364 && **str >= '0' &&
			((negative && **str <= '8') || (!negative && **str <= '7'))))
	{
		*output = *output * 10 + (**str - '0');
		(*str)++;
	}
	if (**str && !ft_strchr("\t\v\r\f\n ", **str))
		*status = -1;
}

/*
**	Skips next whitespaces and converts the next substring to an int. If that
**	substring can be converted to an int, the int_ptr is updated with that
**	value, the *line ptr is updated to the new location in the string, and the
**	function returns 1. If there are only whitespaces and / or we are
**	at the end of the string, the function returns 0 and does nothing.
**	If the found substring can't be converted to an int, the function returns -1
**	and does nothing else.
*/

int			get_next_int(char **line, int *int_ptr)
{
	int		negative;
	int		status;
	int		output;
	char	*str;

	output = 0;
	status = 0;
	str = *line;
	str = handle_blanks_signs(str, &negative, &status);
	while (*str == '0')
	{
		str++;
		status = 1;
	}
	convert_digits(&str, &output, negative, &status);
	if (negative && status > 0)
		output = -(output);
	if (status > 0)
	{
		*line = str;
		*int_ptr = output;
	}
	return (status);
}
