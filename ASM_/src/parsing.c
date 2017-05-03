/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:58:00 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/03 16:52:42 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int ft_join_lines(t_parsing *parsing)
{
	if (!(parsing->input_line = ft_strjoin_free(parsing->input_line, \
		  parsing->clean_line)))
		  return (-1);
	if (!(parsing->input_line = ft_strjoin_free(parsing->input_line, \
		"\n")))
		return (-1);
	return (0);
}

int parse_content(t_parsing *parsing)
{
	int ret;

	ret = 0;
	if (parsing->input_line == NULL)
	{
		if (!(parsing->input_line = ft_strnew(1)))
			  return (-1);
	}
	if (parsing->name_stocked == 1 && parsing->comment_stocked == 1)
	{
		ret = parse_labels(parsing);
		if (ret == -1)
			return (-1);
		if (ret == 1)
		{
			if (ft_join_lines(parsing) == -1)
				return (-1);
			return (0);
		}
		if (ft_join_lines(parsing) == -1)
			return (-1);
	}
	return (0);
}

void init_struct_parsing(t_parsing *parsing)
{
	parsing->clean_line = NULL;
	parsing->line_nb = 0;
	parsing->name_stocked = 0;
	parsing->comment_stocked = 0;
	parsing->input_line = NULL;
}

int parsing_input(t_data *data)
{
    char *line;

	line = NULL;
	init_struct_parsing(&data->parsing);
	while (get_next_line(data->input.fd, &line) > 0)
	{
		data->parsing.line_nb++;
        if (!(data->parsing.clean_line = ft_strtrim_comment(line, COMMENT_CHAR)))
			return (-1);
		if (*data->parsing.clean_line == '\0')
		{
			ft_strdel(&data->parsing.clean_line);
			continue ;
		}
		if (parse_content(&(data->parsing)) == -1)
			return (-1);
		parse_name_comment(&(data->parsing));
		ft_strdel(&data->parsing.clean_line);
    }
	ft_putstr_fd(data->parsing.input_line, 2);
    return (0);
}
