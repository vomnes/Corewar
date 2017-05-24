/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrn_ctype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:28:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/23 13:04:36 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstrn_ctype(const char *str, int (*c_type)(), size_t n)
{
	int	i;

	i = 0;
	while (n && str[i] != '\0')
	{
		if ((*c_type)(str[i]) == 1)
			return (1);
		i++;
		n--;
	}
	return (0);
}
