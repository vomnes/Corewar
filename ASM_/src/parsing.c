/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:58:00 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/12 11:20:40 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define CONTINUE 5

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

static void	clean_struct_parsing(t_parsing *parsing)
{
	ft_strdel(&parsing->label_name);
	ft_strdel(&parsing->clean_line);
	ft_strdel(&parsing->line_label);
	ft_strdel(&parsing->line_opcode);
	ft_strdel(&parsing->line_args);
}

static int	analyse_line(t_parsing *parsing, header_t *header, char **line)
{
	if (!(parsing->clean_line = \
		ft_strtrim_comment(*line, COMMENT_CHAR)))
		return (-1);
	if (*parsing->clean_line == '\0')
	{
		ft_strdel(&parsing->clean_line);
		ft_strdel(&(*line));
		return (CONTINUE);
	}
	if (parse_content(parsing) == -1)
	{
		clean_struct_parsing(parsing);
		return (-1);
	}
	parse_name_comment(parsing, header);
	if (add_new_instruction(&parsing->lst, parsing) == -1)
		return (-1);
	clean_struct_parsing(parsing);
	return (0);
}

static int	analyse_instructions(t_parsing *parsing)
{
	if (parse_opcode(&parsing->lst) == -1)
		return (-1);
	if (get_args(&parsing->lst) == -1)
		return (-1);
	if (parse_args(&parsing->lst) == -1)
		return (-1);
	if (validate_arguments(&parsing->lst) == -1)
		return (-1);
	clean_struct_parsing(parsing);
	return (0);
}

int			parsing_input(t_data *data)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 0;
	init_struct_parsing(&data->parsing);
	while (get_next_line(data->input.fd, &line) > 0)
	{
		data->parsing.line_nb++;
		if ((ret = analyse_line(&data->parsing, &data->header, &line)) == -1)
			return (-1);
		if (ret == CONTINUE)
			continue ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (analyse_instructions(&data->parsing) == -1)
		return (-1);
	return (0);
}
