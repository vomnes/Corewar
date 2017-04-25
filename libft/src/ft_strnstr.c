/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:15:14 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:43:37 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && little[j] == big[i + j] && i + j < len)
			j++;
		if (little[j] == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
