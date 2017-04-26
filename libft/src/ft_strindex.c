/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:37:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/04/26 15:37:42 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strindex(const char *s, const char *to_check)
{
	char *ptr;

	ptr = ft_strstr(s, to_check);
	if (ptr == NULL)
		return (-1);
	else
		return (ptr - s);
}
