/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 11:19:31 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/11 15:03:18 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the CONTENT of the first element in the lists where the function
**	f returns 1
*/

void	*ft_lstfind(t_list *lst, int (*f)(void *, void *), void *comparison)
{
	while (lst && f)
	{
		if (f(lst->content, comparison))
			return (lst->content);
		lst = lst->next;
	}
	return (NULL);
}
