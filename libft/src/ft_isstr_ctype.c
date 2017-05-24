/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstr_ctype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:02:43 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/23 13:03:48 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if the char of the str selected are xxx (c_type function)
** Example :
** if (ft_isstr_ctype(name, ft_isnumber) == 1)
**    ft_putstr("name is a number");
*/

int	ft_isstr_ctype(const char *str, int (*c_type)())
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((*c_type)(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
