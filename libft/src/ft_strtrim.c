/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:48:49 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:49:28 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(char const *s)
{
	int start;

	start = 0;
	while (BLANK(s[start]) && s[start])
		start++;
	return (start);
}

static int	find_end(char const *s, int start)
{
	int end;

	end = 0;
	while (s[end])
		end++;
	if (end > start)
		end--;
	while (BLANK(s[end]) && end > start)
		end--;
	return (end);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*output;
	int		i;
	int		j;

	if (s)
	{
		start = find_start(s);
		end = find_end(s, start);
		output = (char *)malloc((end - start + 2) * sizeof(char));
		if (output)
		{
			i = 0;
			j = start;
			while (j <= end)
				output[i++] = s[j++];
			output[i] = '\0';
			return (output);
		}
	}
	return (NULL);
}
