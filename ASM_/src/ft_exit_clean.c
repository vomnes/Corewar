/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:11:37 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/23 15:38:44 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	delete_lst_args_a(t_args **lst)
{
	t_args *current;

	current = *lst;
	while (current != NULL)
	{
		ft_strdel(&current->content);
		current = current->next;
	}
}

int			ft_exit_clean(t_instructions **lst, int type, t_data *data)
{
	t_instructions *tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		tmp->num_line = 0;
		tmp->is_label = 0;
		ft_strdel(&tmp->line_label);
		ft_strdel(&tmp->label_name);
		ft_strdel(&tmp->line_opcode);
		ft_strdel(&tmp->line_args);
		delete_lst_args_a(&tmp->arg);
		tmp = tmp->next;
	}
	close(data->input.fd);
	close(data->binary_file.fd);
	return (type);
}
