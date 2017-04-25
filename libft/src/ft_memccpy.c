/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:12:57 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:11:53 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *dst_ch;
	unsigned char *src_ch;

	dst_ch = (unsigned char *)dst;
	src_ch = (unsigned char *)src;
	while (n > 0)
	{
		*dst_ch = *src_ch;
		if (*dst_ch == (unsigned char)c)
			return ((void *)(dst_ch + 1));
		dst_ch++;
		src_ch++;
		n--;
	}
	return (NULL);
}
