/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:58:00 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/02 19:44:26 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_is_label_chars(int c)
{
	if (ft_strchr(LABEL_CHARS, (char)c) != NULL)
		return (0);
	else
		return (1);
}

int parse_content(t_parsing *parsing)
{
	if (parsing->name_stocked == 1 && parsing->comment_stocked == 1)
	{
		int i;
		char *content;

		i = 0;
		while (parsing->clean_line[i] != '\0')
		{
			if (parsing->clean_line[i] == ':')
			{
				if (!(content = ft_strndup(parsing->clean_line, ft_charindex(parsing->clean_line, ':'))))
					return (-1);
				break ;
			}
			i++;
		}
		if (ft_isstr_ctype(content, ft_is_label_chars) == 1)
			;
		else
			ft_putendl_fd(content, 2);
	}
	return (0);
}

void init_struct_parsing(t_parsing *parsing)
{
	parsing->clean_line = NULL;
	parsing->line_nb = 0;
	parsing->name_stocked = 0;
	parsing->comment_stocked = 0;
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
		// ft_printf("%s\n", data->parsing.clean_line);
		parse_content(&(data->parsing));
		parse_name_comment(&(data->parsing));
		ft_strdel(&data->parsing.clean_line);
    }
    return (0);
}
