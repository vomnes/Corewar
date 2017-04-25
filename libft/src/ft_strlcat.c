/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:13:04 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:33:42 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (size > 0 && dst[i])
	{
		i++;
		size--;
	}
	while (size > 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
		size--;
	}
	if (size > 0)
		dst[i] = '\0';
	while (src[j])
	{
		j++;
		i++;
	}
	return (i);
}
