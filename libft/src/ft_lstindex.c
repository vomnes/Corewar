/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:06:15 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/08 20:03:51 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns a pointer to the CONTENT of the ith element in the list
**	Returns a Null pointer if the index exceeds the length of the list.
*/

void	*ft_lstindex(t_list *lst, size_t index)
{
	size_t i;

	i = 1;
	while (lst && i < index)
	{
		lst = lst->next;
		i++;
	}
	if (lst)
		return (lst->content);
	return (NULL);
}
