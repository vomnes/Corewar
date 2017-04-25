/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:21:09 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:29:40 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*output;

	length = ft_strlen(s1);
	output = (char *)malloc(sizeof(*output) * (length + 1));
	if (output == NULL)
		return (NULL);
	ft_strcpy(output, s1);
	return (output);
}
