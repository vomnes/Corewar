/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:41:14 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/27 14:00:20 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	!! FREES the string passed in parameter and returns a new string with the
**	character appended at the end. Accepts NULL as an input string.
*/

char	*ft_strappend_char(char *str, char c)
{
	char	*output;
	int		length;
	int		i;

	if (str)
		length = ft_strlen(str);
	else
		length = 0;
	output = ft_strnew(length + 1);
	i = 0;
	if (str)
		while (str[i])
		{
			output[i] = str[i];
			i++;
		}
	output[i] = c;
	output[i + 1] = '\0';
	free(str);
	return (output);
}
