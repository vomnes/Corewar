/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_index_bit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:03:12 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/08 13:39:15 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int check_each_arg(t_instructions *lst)
{
	t_args  *current;
    int     byte_offset;

	current = lst->arg;
    byte_offset = 6;
	while(current != NULL)
	{
        lst->index_bit = (current->type << byte_offset) | lst->index_bit;
		current = current->next;
        byte_offset -= 2;
	}
    return (0);
}

int create_index_bit(t_instructions **lst)
{
    t_instructions *current;

	current = *lst;
	while(current != NULL)
	{
        if (current->line_args)
            check_each_arg(current);
		current = current->next;
	}
    return (0);
}
