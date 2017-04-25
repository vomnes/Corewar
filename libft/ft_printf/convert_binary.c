/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:14:46 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/20 11:14:47 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_itoa_b(unsigned long long int nb, int *k, t_args *elem)
{
	int			len;
	char		str[100];

	ft_bzero(str, 100);
	len = ft_count_ho(nb, 2);
	if (len > 100)
		return (-1);
	len--;
	if (nb == 0)
		str[len] = '0';
	while (nb)
	{
		str[len--] = (nb % 2) + '0';
		nb /= 2;
	}
	ft_manage_hex(str, elem, "0b", k);
	return (elem[*k].arg_len);
}
