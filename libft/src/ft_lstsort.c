/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:31:31 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/15 15:39:22 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This functions uses the bubble sort algorithm to sort the list in ascending
**	order. The function merely swaps the content pointers, and doesn't actually
**	swap the t_list elements. Content sizes get updated accordingly, though.
*/

void	ft_lstsort(t_list *lst, int (*cmp)(void *, void *))
{
	t_list	*current;
	int		sorted;

	sorted = 0;
	while (!sorted)
	{
		current = lst;
		sorted = 1;
		while (current && current->next)
		{
			if (cmp(current->content, current->next->content) > 0)
			{
				sorted = 0;
				ft_lstswap(current, current->next);
			}
			current = current->next;
		}
	}
}
