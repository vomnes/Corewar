/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:03:01 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/08 15:34:55 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lst_add_back(t_list **lst, void const *ctt, size_t ctt_size)
{
	t_list *tmp;

	if (lst)
	{
		tmp = *lst;
		if (*lst)
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = ft_lstnew(ctt, ctt_size);
		}
		else
			*lst = ft_lstnew(ctt, ctt_size);
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *current;

	current = NULL;
	if (lst || f)
	{
		while (lst != NULL)
		{
			ft_lst_add_back(&current, f(lst)->content, f(lst)->content_size);
			lst = lst->next;
		}
		return (current);
	}
	return (NULL);
}
