/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:08:15 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/08 19:27:45 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_atoi_error takes in a string and a pointer to an int and returns that
**	same pointer, updated to the value of the int expressed by the string.
**	If the string is badly formatted or its value can't fit in an int, the
**	function returns a NULL pointer.
*/

static char	*handle_blanks_signs(char *str, int *negative)
{
	*negative = 0;
	while (*str == '\t' || *str == '\v' || *str == '\r' || *str == '\f' ||
			*str == '\n' || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		*negative = 1;
		str++;
	}
	return (str);
}

static int	*handle_limits(char *str, int *return_ptr, int negative)
{
	if (return_ptr)
	{
		if ((*return_ptr < 214748364 && (*str >= '0' && *str <= '9')) ||
				(*return_ptr == 214748364 && *str >= '0' &&
				((negative && *str <= '8') || (!negative && *str <= '7'))))
		{
			*return_ptr = *return_ptr * 10 + (*str - '0');
			str++;
		}
		if (*str)
			return_ptr = NULL;
	}
	return (return_ptr);
}

int			*ft_atoi_error(char *str, int *output)
{
	int negative;
	int	count;
	int	*return_ptr;

	*output = 0;
	return_ptr = NULL;
	str = handle_blanks_signs(str, &negative);
	while (*str == '0')
	{
		return_ptr = output;
		str++;
	}
	count = 0;
	while (count < 9 && *str > 47 && *str < 58 && *str)
	{
		return_ptr = output;
		*output = *output * 10 + (*str - '0');
		count++;
		str++;
	}
	return_ptr = handle_limits(str, return_ptr, negative);
	if (negative)
		*output = -(*output);
	return (return_ptr);
}
