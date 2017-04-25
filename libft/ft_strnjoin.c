/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:04:17 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/30 16:05:10 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char *new_str;

	if (!s1 || !s2)
		return (NULL);
	if (!(new_str = ft_strnew(ft_strlen(s1) + n)))
		return (NULL);
	ft_strcat(new_str, s1);
	ft_strncat(new_str, s2, n);
	return (new_str);
}
