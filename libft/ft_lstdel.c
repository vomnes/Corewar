/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:49:40 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/08 15:03:58 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;
	t_list *current2;

	current = *alst;
	while (current != NULL)
	{
		del(current->content, current->content_size);
		current2 = current;
		current = current->next;
		free(current2);
		current2 = NULL;
	}
	*alst = NULL;
}
