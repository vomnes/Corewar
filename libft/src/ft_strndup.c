/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:37:04 by vomnes            #+#    #+#             */
/*   Updated: 2017/04/26 15:37:12 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*dest;

	if (!(dest = ft_strnew(n)))
		return (NULL);
	i = 0;
	while (n && s1[i])
	{
		dest[i] = s1[i];
		i++;
		n--;
	}
	dest[i] = '\0';
	return (dest);
}
