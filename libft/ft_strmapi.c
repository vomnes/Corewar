/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:43:56 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/05 11:48:22 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*new_s;

	if (s == NULL || f == NULL)
		return (NULL);
	new_s = ft_strnew(ft_strlen(s));
	if (!new_s)
		return (NULL);
	index = 0;
	while (s[index])
	{
		new_s[index] = f(index, s[index]);
		index++;
	}
	return (new_s);
}
