/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_nocopy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:35:25 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/10 10:56:07 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_nocopy(void *content, size_t content_size)
{
	t_list	*node;

	if ((node = (t_list *)malloc(sizeof(*node))))
	{
		if (content)
		{
			node->content = content;
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
