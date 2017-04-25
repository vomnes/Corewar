/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend_char_before.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 22:39:00 by atrudel           #+#    #+#             */
/*   Updated: 2016/12/06 22:44:50 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	!! FREES the string passed in parameter and returns a new string with the
**	character added at the beginning. Accepts NULL as an input string.
*/

char	*ft_strappend_char_before(char *str, char c)
{
	char	*output;
	int		length;
	int		i;

	if (str)
		length = ft_strlen(str);
	else
		length = 0;
	output = ft_strnew(length + 1);
	output[0] = c;
	i = 0;
	if (str)
		while (str[i])
		{
			output[i + 1] = str[i];
			i++;
		}
	output[i + 1] = '\0';
	free(str);
	return (output);
}
