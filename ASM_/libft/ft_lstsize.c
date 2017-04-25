/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:42:25 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/24 17:36:43 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *list)
{
	t_list *temp;
	size_t count;

	count = 0;
	temp = list;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
