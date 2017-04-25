/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:09:05 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 15:02:25 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length_int(long int nbr)
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

char		*ft_itoa(int n)
{
	char		*output;
	long int	number;
	int			length;

	length = length_int((long int)n);
	if (!(output = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	output[length] = '\0';
	number = (n < 0) ? -(long int)n : (long int)n;
	while (--length > -1)
	{
		output[length] = number % 10 + '0';
		number = number / 10;
	}
	if (n < 0)
		output[0] = '-';
	return (output);
}
