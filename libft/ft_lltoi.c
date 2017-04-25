/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 08:45:29 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/02 08:47:13 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_lltoi(const char *nptr)
{
	int				i;
	long long int	result;
	int				neg;

	i = 0;
	result = 0;
	neg = 0;
	while ((nptr[i] == '\n') || (nptr[i] == '\t') || (nptr[i] == '\v') ||
			(nptr[i] == ' ') || (nptr[i] == '\f') || (nptr[i] == '\r'))
		i++;
	if (nptr[i] == '-')
		neg = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	if (neg == 1)
		result = -result;
	return (result);
}
