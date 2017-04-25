/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:58:08 by vomnes            #+#    #+#             */
/*   Updated: 2016/12/14 12:30:15 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char const *src, char c)
{
	char	*new_str;
	size_t	len;

	if (!src || !c)
		return (NULL);
	len = ft_strlen(src);
	if (!(new_str = ft_strnew(len + 1)))
		return (NULL);
	ft_strcat(new_str, src);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	return (new_str);
}
