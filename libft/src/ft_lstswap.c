/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:20:50 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/15 15:29:12 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This function swaps the CONTENT of the t_list structures. It also updates
**	the content sizes. Returns 1 upon successful swapping. 0 otherwise.
*/

int		ft_lstswap(t_list *element1, t_list *element2)
{
	void	*tmp;
	size_t	tmp_size;

	if (!element1 || !element2)
		return (0);
	tmp = element1->content;
	tmp_size = element1->content_size;
	element1->content = element2->content;
	element1->content_size = element2->content_size;
	element2->content = tmp;
	element2->content_size = tmp_size;
	return (1);
}
