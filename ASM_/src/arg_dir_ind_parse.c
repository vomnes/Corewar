/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_dir_ind_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 19:02:58 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/10 16:42:06 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_label_exist(t_instructions *lst, char *label_to_check)
{
	t_instructions *tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->label_name != NULL)
		{
			if (ft_strcmp(tmp->label_name, label_to_check) == 0)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

/*
** arg_dir_ind_parse : Check if arguments Direct and Indirect are correct. 
*/

int			arg_dir_ind_parse(t_args *current, char num_arg, int num_line, \
t_instructions *check_label)
{
	char *content;

	content = (current->type < 3) ? current->content + 1 : current->content;
	if (current->type == DIR_CODE || current->type == IND_CODE)
	{
		if (*content == LABEL_CHAR)
		{
			if (ft_label_exist(check_label, content + 1) == 0)
			{
				ft_dprintf(2, "Undefined label [arg %d] - Line %d\n", \
				num_arg, num_line);
				return (-1);
			}
			current->label = content + 1;
		}
		else if (ft_isnumber_syntax(content, 1) == 1)
			current->value = ft_lltoi(content);
		else
		{
			ft_dprintf(2, "Undefined syntax [arg %d] - Line %d\n", \
			num_arg, num_line);
			return (-1);
		}
	}
	return (0);
}
