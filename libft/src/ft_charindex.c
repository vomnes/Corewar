/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charindex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:04:22 by vomnes            #+#    #+#             */
/*   Updated: 2017/04/27 18:05:06 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charindex(const char *s, char c)
{
	char *ptr;

	ptr = ft_strchr(s, c);
	if (ptr == NULL)
		return (-1);
	else
		return (ptr - s);
}
