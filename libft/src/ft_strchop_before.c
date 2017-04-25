/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchop_before.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:48:43 by atrudel           #+#    #+#             */
/*   Updated: 2017/01/25 15:48:44 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	!! FREES the string passed in parameter and returns a new string with n
**	characters chopped at the beginning.
*/

char	*ft_strchop_before(char *str, size_t n)
{
	char	*output;
	size_t	length;
	int		i;

	if (str)
		length = ft_strlen(str);
	else
		length = 0;
	if (n < length)
	{
		output = ft_strnew(length - n);
		i = 0;
		if (str && output)
			while (str[i + n])
			{
				output[i] = str[i + n];
				i++;
			}
	}
	else
		output = ft_strnew(0);
	free(str);
	return (output);
}
