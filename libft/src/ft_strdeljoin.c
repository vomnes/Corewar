/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdeljoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:04:24 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/27 14:08:08 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	FREES both strings passed as input an concatenates them into a new one.
*/

char	*ft_strdeljoin(char *s1, char *s2)
{
	char *output;

	if (s1 && s2)
	{
		output = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (output)
		{
			ft_strcpy(output, s1);
			ft_strcat(output, s2);
		}
	}
	else if (s1 || s2)
	{
		output = ft_strnew(ft_strlen(s1 ? s1 : s2));
		if (output)
			ft_strcpy(output, s1 ? s1 : s2);
	}
	else
		output = NULL;
	free(s1);
	free(s2);
	return (output);
}
