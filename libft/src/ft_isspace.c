/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:13:31 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/03 11:13:48 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	return ((unsigned char)c == 32 || (unsigned char)c == '\t'
			|| (unsigned char)c == '\n' || (unsigned char)c == '\v'
			|| (unsigned char)c == '\f' || (unsigned char)c == '\r');
}
