/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:13:23 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 18:42:04 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n > 1)
	{
		if (*ptr1 != *ptr2)
			break ;
		ptr1++;
		ptr2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*ptr1 - *ptr2);
}
