/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:57:33 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/04 15:08:50 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int pos;

	i = 0;
	if (*needle == '\0')
		return (char*)(haystack);
	while (haystack[i])
	{
		pos = 0;
		while (haystack[pos + i] == needle[pos])
		{
			if (needle[pos + 1] == '\0')
				return (char*)(haystack + i);
			pos++;
		}
		i++;
	}
	return (NULL);
}
