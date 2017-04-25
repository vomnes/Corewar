/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:51:37 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/09 10:55:25 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*new_big;
	char	*new_little;
	size_t	new_len;
	size_t	i;

	if (*little == '\0')
		return (char*)(big);
	new_big = (char*)big;
	new_little = (char*)little;
	new_len = ft_strlen(new_little);
	i = 0;
	while (new_big[i] != '\0' && (i + new_len) <= len)
	{
		if (ft_strncmp(big + i, little, new_len) == 0)
			return (new_big + i);
		i++;
	}
	return (NULL);
}
