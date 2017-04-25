/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 09:49:09 by vomnes            #+#    #+#             */
/*   Updated: 2016/12/18 16:43:15 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long long int nb, int base)
{
	int count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / base;
		count++;
	}
	return (count);
}

char		*ft_itoa_base(long long int nb, int base)
{
	long long int	n;
	int				sign_len[2];
	char			*str;

	n = nb;
	sign_len[1] = 0;
	if (n < 0)
		n = -n;
	if (n < 0 && base == 10)
		sign_len[1] = 1;
	sign_len[0] = ft_count(n, base) + sign_len[1];
	if (!(str = ft_strnew(sign_len[0])))
		return (NULL);
	sign_len[0]--;
	if (nb == 0)
		str[sign_len[0]] = '0';
	while (n)
	{
		(n % base <= 9) ? (str[sign_len[0]--] = (n % base) + '0') :
		(str[sign_len[0]--] = (n % base) + 'A' - 10);
		n /= base;
	}
	if (sign_len[1] == 1)
		str[sign_len[0]] = '-';
	return (str);
}
