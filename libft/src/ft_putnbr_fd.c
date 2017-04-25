/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:21:23 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 14:23:10 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	special_case(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (1);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
		return (1);
	}
	return (0);
}

void		ft_putnbr_fd(int n, int fd)
{
	long int	rev;
	int			count;

	if (special_case(n, fd))
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
			ft_putchar_fd(rev % 10 + '0', fd);
			rev = rev / 10;
			count--;
		}
	}
}
