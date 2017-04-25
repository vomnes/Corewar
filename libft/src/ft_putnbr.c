/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:23:25 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:24:08 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	special_case(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (1);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
		return (1);
	}
	return (0);
}

void		ft_putnbr(int n)
{
	long int	rev;
	int			count;

	if (special_case(n))
	{
	}
	else
	{
		rev = 0;
		count = (n == 0 ? 1 : 0);
		while (n)
		{
			rev = rev * 10 + (long int)n % 10;
			n = n / 10;
			count++;
		}
		while (count > 0)
		{
			ft_putchar(rev % 10 + '0');
			rev = rev / 10;
			count--;
		}
	}
}
