/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:30:05 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:30:18 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		if (ft_strcmp(s1, s2) == 0)
			return (1);
		else
			return (0);
	}
	else if (s1 == NULL && s2 == NULL)
		return (1);
	else
		return (0);
}
