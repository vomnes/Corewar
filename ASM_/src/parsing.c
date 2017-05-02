/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:58:00 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/02 14:49:34 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
		printf("%s\n", data->parsing.clean_line);
		parse_name_comment(&(data->parsing));
		ft_strdel(&data->parsing.clean_line);
    }
    return (0);
}
