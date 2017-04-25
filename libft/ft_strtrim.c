/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:59:20 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/09 10:55:49 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new_str;
	int		index;
	size_t	len;
	int		new_len;

	if (!s)
		return (NULL);
	index = 0;
	len = ft_strlen((char*)s);
	while (s[index] == ' ' || s[index] == '\n' || s[index] == '\t')
		index++;
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	new_len = len - index;
	if (new_len <= 0)
		new_len = 0;
	new_str = ft_strnew(new_len);
	if (!new_str)
		return (NULL);
	new_str = ft_strsub(s, index, new_len);
	return (new_str);
}
