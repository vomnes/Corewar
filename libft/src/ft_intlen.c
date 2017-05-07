/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 19:05:46 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/07 19:06:51 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int nbr)
{
	size_t length;

	length = 0;
	if (nbr <= 0)
		length++;
	while (nbr)
	{
		nbr = nbr / 10;
		length++;
	}
	return (length);
}
