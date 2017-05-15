/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:23:17 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/15 16:11:19 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		init_arg(t_args **arg)
{
	(*arg)->content = NULL;
	(*arg)->type = 0;
	(*arg)->t_arg = 0;
	(*arg)->value = 0;
	(*arg)->op = 0;
	(*arg)->value_2 = 0;
	(*arg)->label = NULL;
}

static t_args	*arg_add_elem(char *content)
{
	t_args *new_arg;

	new_arg = NULL;
	if (!(new_arg = (t_args*)malloc(sizeof(t_args))))
		return (NULL);
	init_arg(&new_arg);
	if (content != NULL && *content != '\0')
	{
		if (!(new_arg->content = ft_strdup(content)))
			return (NULL);
	}
	return (new_arg);
}

/*
** add_arg : Add at the end of the linked list t_args
** an argument.
*/

int				add_arg(t_args **lst_head, char *content)
{
	t_args	*new_node;

	new_node = *lst_head;
	if (*lst_head == NULL)
	{
		if (!(*lst_head = arg_add_elem(content)))
			return (-1);
		(*lst_head)->next = NULL;
	}
	else
	{
		while (new_node->next != NULL)
			new_node = new_node->next;
		if (!(new_node->next = arg_add_elem(content)))
			return (-1);
		new_node->next->next = NULL;
	}
	return (0);
}
