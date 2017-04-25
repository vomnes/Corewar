/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_of.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 10:05:20 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/31 15:01:04 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_index(const char *s, int c)
{
	char *ptr;

	ptr = ft_strchr(s, c);
	if (ptr == NULL)
		return (-1);
	else
		return (ptr - s);
}
