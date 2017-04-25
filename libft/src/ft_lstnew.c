/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:42:38 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 17:42:44 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if ((node = (t_list *)malloc(sizeof(*node))))
	{
		if (content)
		{
			if ((node->content = ft_memalloc(content_size)))
				ft_memcpy(node->content, content, content_size);
			node->content_size = content_size;
		}
		else
		{
			node->content = NULL;
			node->content_size = 0;
		}
		node->next = NULL;
	}
	return (node);
}
