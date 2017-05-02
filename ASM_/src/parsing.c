/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:58:00 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/02 13:28:58 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_isprint_nospace(int c)
{
	if (c > 32 && c < 127)
		return (1);
	else
		return (0);
}

void check_header_content(const char *cmd_string, unsigned int content_len,
t_parsing *parsing)
{
    char *name;
    int index_open;
    int index_close;

    if (ft_strncmp(parsing->clean_line, cmd_string, ft_strlen(cmd_string)) == 0)
    {
        name = parsing->clean_line + ft_strlen(cmd_string);
        index_open = ft_charindex(name, '\"');
        if (ft_isstrn_ctype(name, ft_isprint_nospace, index_open))
        {
            ft_printf("Syntax error before content of %s - Line %d\n", cmd_string, parsing->line_nb);
            exit (-1);
        }
        if (ft_nb_occ(name, '\"') != 2)
        {
            ft_printf("Syntax error - %s - Line %d\n", cmd_string, parsing->line_nb);
            exit (-1);
        }
        index_close = ft_charindex(name + index_open + 1, '\"');
        if (index_close > (int)content_len)
        {
            ft_printf("Champion %s too long, %d character(s) over the limit (Max length %d)\n",\
            cmd_string, index_close - content_len, content_len);
            exit (-1);
        }
        if (ft_isstr_ctype(name + (index_open + index_close + 2), ft_isprint_nospace))
        {
            ft_printf("Syntax error after content %s - Line %d\n", cmd_string, parsing->line_nb);
            exit (-1);
        }
    }
	if (ft_strncmp(parsing->clean_line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
		parsing->name_stocked = 1;
	else if (ft_strncmp(parsing->clean_line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0)
		parsing->comment_stocked = 1;
}

int parsing_input(t_data *data)
{
    char *line;

	line = NULL;
    data->parsing.clean_line = NULL;
	data->parsing.line_nb = 0;
	data->parsing.name_stocked = 0;
	data->parsing.comment_stocked = 0;
	while (get_next_line(data->input.fd, &line) > 0)
	{
		data->parsing.line_nb++;
        if (!(data->parsing.clean_line = ft_strtrim_comment(line, COMMENT_CHAR)))
        {
            ft_strdel(&line);
            return (-1);
        }
		if (*data->parsing.clean_line == '\0')
			continue ;
		printf("%s\n", data->parsing.clean_line);
        check_header_content(NAME_CMD_STRING, PROG_NAME_LENGTH, &data->parsing);
        check_header_content(COMMENT_CMD_STRING, COMMENT_LENGTH, &data->parsing);
		if (ft_strncmp(data->parsing.clean_line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) != 0 &&
		ft_strncmp(data->parsing.clean_line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) != 0)
		{
			if (data->parsing.name_stocked == 0 && data->parsing.comment_stocked == 0)
			{
				ft_putendl_fd("Name and Comment undefined", 2);
				exit (-1);
			}
			else if (data->parsing.comment_stocked == 0)
			{
				ft_putendl_fd("Comment undefined", 2);
				exit (-1);
			}
			else if (data->parsing.name_stocked == 0)
			{
				ft_putendl_fd("Name undefined", 2);
				exit (-1);
			}
		}
        ft_strdel(&line);
    }
    ft_strdel(&line);
    return (0);
}

// check nb \"
// if (nb != 2)
//     error syntax NAME_CMD_STRING
// if ((name + (index_1 + index_2)) is strprint)
//     error syntax NAME_CMD_STRING
