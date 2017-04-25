/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:43:00 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/09 10:55:05 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_s;
	size_t	len_s;
	int		i;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen((char*)s);
	new_s = ft_strnew(len_s);
	if (!new_s)
		return (NULL);
	i = -1;
	while (s[++i])
		new_s[i] = f(s[i]);
	new_s[i] = '\0';
	return (new_s);
}
