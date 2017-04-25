/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:43:37 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:43:05 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*output;
	size_t	i;

	output = (char *)malloc(size + 1);
	i = 0;
	if (output)
		while (i < size + 1)
		{
			output[i] = '\0';
			i++;
		}
	return (output);
}
