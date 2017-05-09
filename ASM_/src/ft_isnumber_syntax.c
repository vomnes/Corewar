/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 14:00:19 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/09 18:19:14 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_isstr_type(const char *str, int (*c_type)())
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((*c_type)(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int			ft_isnumber_syntax(char *str, char sign)
{
	if (*str == '-' && sign == 1)
	{
		if (ft_isstr_type(str + 1, ft_isdigit) == 0)
			return (-1);
	}
	else
	{
		if (ft_isstr_type(str, ft_isdigit) == 0)
			return (-1);
	}
	return (1);
}
