/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_label_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:05:01 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/15 19:52:29 by vomnes           ###   ########.fr       */
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

static int result_expression(t_args *arg)
{
	int result;

	result = 0;
	if (arg->op == '+')
		result = arg->value + arg->value_2;
	else if (arg->op == '-')
		result = arg->value - arg->value_2;
	else if (arg->op == '*')
		result = arg->value * arg->value_2;
	else if (arg->op == '/')
	{
		if (arg->value_2 == 0)
			return (0);
		result = arg->value / arg->value_2;
	}
	else if (arg->op == '%')
	{
		if (arg->value_2 == 0)
			return (0);
		result = arg->value % arg->value_2;
	}
	return (result);
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
		if (current->op != 0)
			current->value = result_expression(current);
		current = current->next;
	}
}

/*
** set_label_value : Set the value of each argument using label (result between
** current index octet and label's index octet).
*/

int			set_value(t_instructions **lst)
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
