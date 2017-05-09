/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_label_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:05:01 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/09 19:09:40 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_label_octet_index(t_instructions *lst, char *current_label)
{
	t_instructions *tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->label_name != NULL)
		{
			if (ft_strcmp(tmp->label_name, current_label) == 0)
				return (tmp->index_octet);
		}
		tmp = tmp->next;
	}
	return (0);
}

static void	check_each_arg(t_instructions **lst, t_instructions *instructions)
{
	t_args *current;

	current = (*lst)->arg;
	while (current != NULL)
	{
		if (current->label != NULL)
		{
			current->value = get_label_octet_index(instructions, \
			current->label) - (*lst)->index_octet;
		}
		current = current->next;
	}
}

// ft_printf("%s : %d = %d - %d\n", current->label, current->value, get_label_octet_index(instructions, \
// current->label), (*lst)->index_octet);

int			set_label_value(t_instructions **lst)
{
	t_instructions *current;

	current = *lst;
	while (current != NULL)
	{
		if (current->opcode > 0)
			check_each_arg(&current, *lst);
		current = current->next;
	}
	return (0);
}
