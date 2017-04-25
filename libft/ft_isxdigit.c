/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:02:22 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/25 18:03:01 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isxdigit(int c)
{
	return (ft_isdigit((unsigned char)c) ||
	((unsigned char)c >= 'A' && (unsigned char)c <= 'F') ||
	((unsigned char)c >= 'a' && (unsigned char)c <= 'f'));
}
