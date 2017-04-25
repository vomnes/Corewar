/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:59:57 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:10:57 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*output;
	size_t	i;

	output = malloc(size);
	i = 0;
	if (output)
		while (i < size)
		{
			((unsigned char *)output)[i] = 0;
			i++;
		}
	return (output);
}
