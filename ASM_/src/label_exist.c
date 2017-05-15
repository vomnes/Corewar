/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_exist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:31:22 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/15 18:33:25 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	label_exist(t_instructions *lst, char *label_to_check)
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
