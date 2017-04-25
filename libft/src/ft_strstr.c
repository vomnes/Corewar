/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:18:19 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:47:51 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (little[j] && little[j] == big[i + j])
			j++;
		if (little[j] == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
