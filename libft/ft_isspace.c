/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:26:05 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/08 18:33:53 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	return ((unsigned char)c == 32 || (unsigned char)c == '\t'
			|| (unsigned char)c == '\n' || (unsigned char)c == '\v'
			|| (unsigned char)c == '\f' || (unsigned char)c == '\r');
}
