/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:32:48 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:33:13 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (output);
}
