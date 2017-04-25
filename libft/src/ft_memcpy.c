/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:13:35 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:15:43 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_char;
	unsigned char *src_char;

	dst_char = (unsigned char *)dst;
	src_char = (unsigned char *)src;
	while (n > 0)
	{
		*dst_char = *src_char;
		dst_char++;
		src_char++;
		n--;
	}
	return (dst);
}
