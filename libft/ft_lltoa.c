/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 10:38:55 by vomnes            #+#    #+#             */
/*   Updated: 2016/12/21 10:50:33 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(long long unsigned int nb)
{
	int count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char			*ft_lltoa(long long int nb)
{
	long long int	n;
	int				sign_len[2];
	char			*str;

	n = nb;
	sign_len[1] = 0;
	if (n < 0)
	{
		sign_len[1] = 1;
		n = -n;
	}
	sign_len[0] = ft_count(n) + sign_len[1];
	if (!(str = ft_strnew(sign_len[0])))
		return (NULL);
	sign_len[0]--;
	if (nb == 0)
		str[sign_len[0]] = '0';
	while (n)
	{
		str[sign_len[0]--] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign_len[1] == 1)
		str[sign_len[0]] = '-';
	return (str);
}
