/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:13:58 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:17:32 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*buf;
	unsigned char	*dst_ch;
	unsigned char	*src_ch;

	dst_ch = (unsigned char *)dst;
	src_ch = (unsigned char *)src;
	if (!(buf = (unsigned char *)malloc(len)))
		return (dst);
	i = 0;
	while (i < len)
	{
		buf[i] = src_ch[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst_ch[i] = buf[i];
		i++;
	}
	free(buf);
	return (dst);
}
