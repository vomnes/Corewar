/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:43:17 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:39:38 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*output;
	unsigned int	i;

	if (s)
	{
		output = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (output)
		{
			i = 0;
			while (s[i])
			{
				output[i] = f(i, s[i]);
				i++;
			}
			output[i] = '\0';
		}
		return (output);
	}
	else
		return (NULL);
}
