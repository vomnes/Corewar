/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:59:31 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/12 10:59:41 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_struct_parsing(t_parsing *parsing)
{
	parsing->line_nb = 0;
	parsing->label_name = NULL;
	parsing->clean_line = NULL;
	parsing->line_label = NULL;
	parsing->line_opcode = NULL;
	parsing->line_args = NULL;
	parsing->lst = NULL;
	parsing->name_stocked = 0;
	parsing->comment_stocked = 0;
	parsing->name_comment_stocked = 0;
}
