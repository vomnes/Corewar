/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:58:00 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/09 19:44:42 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	parse_content(t_parsing *parsing)
{
	int ret;

	ret = 0;
	if (parsing->name_stocked == 1 && parsing->comment_stocked == 1)
	{
		ret = parse_labels(parsing);
		if (ret == -1)
			return (-1);
		if (ret == 1)
		{
			if (!(parsing->line_opcode = ft_strdup(parsing->clean_line)))
				return (-1);
			return (0);
		}
		ft_strdel(&(parsing->line_label));
		if (!(parsing->line_opcode = ft_strdup(parsing->clean_line)))
			return (-1);
	}
	return (0);
}

static void	init_struct_parsing(t_parsing *parsing)
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

static void	clean_struct_parsing(t_parsing *parsing)
{
	ft_strdel(&parsing->label_name);
	ft_strdel(&parsing->clean_line);
	ft_strdel(&parsing->line_label);
	ft_strdel(&parsing->line_opcode);
}

int			parsing_input(t_data *data)
{
	char *line;
	char *opcode_name;

	line = NULL;
	opcode_name = NULL;
	init_struct_parsing(&data->parsing);
	while (get_next_line(data->input.fd, &line) > 0)
	{
		data->parsing.line_nb++;
		if (!(data->parsing.clean_line = \
			ft_strtrim_comment(line, COMMENT_CHAR)))
			return (-1);
		if (*data->parsing.clean_line == '\0')
		{
			ft_strdel(&data->parsing.clean_line); // Free line
			ft_strdel(&line);
			continue ;
		}
		if (parse_content(&(data->parsing)) == -1)
		{
			clean_struct_parsing(&(data->parsing));
			return (-1);
		}
		parse_name_comment(&(data->parsing), &(data->header));
		if (add_new_instruction(&(data->parsing.lst), &data->parsing) == -1)
			return (-1);
		clean_struct_parsing(&(data->parsing));
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (parse_opcode(&data->parsing.lst) == -1)
		return (-1);
	if (get_args(&data->parsing.lst) == -1)
		return (-1);
	if (parse_args(&data->parsing.lst) == -1)
		return (-1);
	if (validate_arguments(&data->parsing.lst) == -1)
		return (-1);
	clean_struct_parsing(&(data->parsing));
	// print_instructions_list(data->parsing.lst);
	return (0);
}

// ft_printf("------------[I]------------\n");
// ft_printf("parsing->line_nb = %d\n", data->parsing.line_nb);
// ft_printf("parsing->line_label = %s\n", data->parsing.line_label);
// ft_printf("parsing->label_name = %s\n", data->parsing.label_name);
// ft_printf("parsing->line_opcode = $%s$\n", data->parsing.line_opcode);
// ft_printf("------------[O]-----------\n");

// st	r1, :ld1

// clean_struct_parsing(&(data->parsing));
// delete_lst_instructions(data->parsing.lst);

// sleep(42);
