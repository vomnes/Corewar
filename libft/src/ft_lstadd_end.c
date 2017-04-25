/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:41:35 by atrudel           #+#    #+#             */
/*   Updated: 2016/11/09 18:07:52 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list *current;

	if (alst && new)
	{
		current = *alst;
		if (current)
		{
			while (current->next)
				current = current->next;
			current->next = new;
		}
		else
		{
			*alst = new;
		}
	}
}
