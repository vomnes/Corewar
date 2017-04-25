/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:06:03 by atrudel           #+#    #+#             */
/*   Updated: 2017/04/20 11:34:58 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list **alst, t_list *to_delete,
		void (*del)(void *, size_t))
{
	if (alst)
	{
		while (*alst)
		{
			if (*alst == to_delete)
			{
				*alst = to_delete->next;
				ft_lstdelone(&to_delete, del);
				return ;
			}
			if (*alst)
				alst = &((*alst)->next);
		}
	}
}
