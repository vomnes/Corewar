/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_display_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:50:50 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/24 17:37:32 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_display_int(t_list *list)
{
	t_list *temp;

	temp = list;
	while (temp != NULL)
	{
		ft_putnbr((int)temp->content);
		temp = temp->next;
	}
}
