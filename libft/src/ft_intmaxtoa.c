/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxtoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:13:52 by atrudel           #+#    #+#             */
/*   Updated: 2016/12/13 20:14:23 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length_intmax(intmax_t nbr)
{
	int length;

	length = 0;
	if (nbr <= 0)
		length++;
	while (nbr)
	{
		nbr = nbr / 10;
		length++;
	}
	return (length);
}

static int	handle_intmax_min(char *output, intmax_t n)
{
	if (n == INTMAX_MIN)
	{
		ft_strcpy(output, "-9223372036854775808");
		return (1);
	}
	return (0);
}

char		*ft_intmaxtoa(intmax_t n)
{
	char		*output;
	intmax_t	number;
	int			length;

	length = length_intmax(n);
	if (!(output = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	output[length] = '\0';
	if (handle_intmax_min(output, n))
		return (output);
	number = (n < 0) ? -n : n;
	while (--length > -1)
	{
		output[length] = number % 10 + '0';
		number = number / 10;
	}
	if (n < 0)
		output[0] = '-';
	return (output);
}
