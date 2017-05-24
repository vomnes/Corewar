/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:38:23 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/23 13:06:37 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strtab_len(char **tab)
{
	size_t	count;

	count = 0;
	if (tab == NULL)
		return (0);
	while (tab[count] != NULL)
		count++;
	return (count);
}
