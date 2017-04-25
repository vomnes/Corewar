/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:03:34 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/11 15:05:45 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the CONTENT of the last element in the list
*/

void	*ft_lstlast(t_list *lst)
{
	while (lst)
		lst = lst->next;
	if (lst)
		return (lst->content);
	return (NULL);
}
