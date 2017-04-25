/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:49:21 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/10 12:48:14 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;

	if (dest == src)
		return (dest);
	new_dest = (unsigned char*)dest;
	new_src = (unsigned char*)src;
	if (new_src < new_dest)
	{
		new_dest = new_dest + n - 1;
		new_src = new_src + n - 1;
		while (n--)
			*new_dest-- = *new_src--;
	}
	else
		while (n--)
			*new_dest++ = *new_src++;
	return (dest);
}
