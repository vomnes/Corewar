/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_display_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:49:17 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/24 17:38:04 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_display_s(t_list *list)
{
	t_list *temp;

	temp = list;
	while (temp != NULL)
	{
		ft_putendl(temp->content);
		temp = temp->next;
	}
}
