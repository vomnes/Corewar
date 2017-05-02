/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:48:11 by atrudel           #+#    #+#             */
/*   Updated: 2017/05/02 15:01:09 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	i;
	size_t	j;

	if (s)
	{
		output = (char *)malloc((len + 1) * sizeof(char));
		if (output)
		{
			i = (size_t)start;
			j = 0;
			while (j < len && s[i] != '\0')
				output[j++] = s[i++];
			output[j] = '\0';
		}
		return (output);
	}
	else
		return (NULL);
}
