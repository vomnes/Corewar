/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:47:52 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/11 16:52:04 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			i;

	new_dest = (unsigned char*)dest;
	new_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		new_dest[i] = new_src[i];
		if (new_src[i] == (unsigned char)c)
			return (dest + 1 + i);
		i++;
	}
	return (NULL);
}
