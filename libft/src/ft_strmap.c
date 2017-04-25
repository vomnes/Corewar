/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:30:10 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:38:54 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*output;
	int		i;

	if (s)
	{
		output = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (output)
		{
			i = 0;
			while (s[i])
			{
				output[i] = f(s[i]);
				i++;
			}
			output[i] = '\0';
		}
		return (output);
	}
	else
		return (NULL);
}
