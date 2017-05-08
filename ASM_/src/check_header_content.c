/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:09:41 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/08 17:17:06 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_strcat_name(char const *s, char prog_name[PROG_NAME_LENGTH + 1], \
size_t len, const char *cmd_string)
{
	int		i;

	if (!s)
		return ;
	if (ft_strcmp(cmd_string, NAME_CMD_STRING) == 0)
	{
		i = 0;
		while ((int)len)
		{
			prog_name[i] = s[i];
			i++;
			len--;
		}
		prog_name[i] = '\0';
	}
}

void	ft_strcat_comment(char const *s, char comment[COMMENT_LENGTH + 1], \
size_t len, const char *cmd_string)
{
	int		i;

	if (!s)
		return ;
	if (ft_strcmp(cmd_string, COMMENT_CMD_STRING) == 0)
	{
		i = 0;
		while ((int)len)
		{
			comment[i] = s[i];
			i++;
			len--;
		}
		comment[i] = '\0';
	}
}

static void error_a(char *name, t_parsing *parsing, const char *cmd_string)
{
	int index_open;

	index_open = ft_charindex(name, '\"');
	if (ft_isstrn_ctype(name, ft_isprint_nospace, index_open))
	{
		ft_dprintf(2, "Syntax error before content of %s - Line %d\n", \
		cmd_string, parsing->line_nb);
		exit (-1);
	}
	if (ft_nb_occ(name, '\"') != 2)
	{
		ft_dprintf(2, "Syntax error - %s - Line %d\n", \
		cmd_string, parsing->line_nb);
		exit (-1);
	}
}

static void error_b(char *name, t_parsing *parsing, const char *cmd_string, \
int content_len)
{
	int index_open;
	int index_close;

	index_open = ft_charindex(name, '\"');
	index_close = ft_charindex(name + index_open + 1, '\"');
	if (index_close > (int)content_len)
	{
		ft_dprintf(2, "Champion %s too long, %d character(s) over the \
	limit (Max length %d)\n",\
		cmd_string, index_close - content_len, content_len);
		exit (-1);
	}
	if (ft_isstr_ctype(name + (index_open + index_close + 2), \
    ft_isprint_nospace))
	{
		ft_dprintf(2, "Syntax error after content %s - Line %d\n", \
		cmd_string, parsing->line_nb);
		exit (-1);
	}
}

void check_header_content(const char *cmd_string, unsigned int content_len,
t_parsing *parsing, header_t *header)
{
    char *name;
    int index_open;
    int index_close;

    if (ft_strncmp(parsing->clean_line, cmd_string, ft_strlen(cmd_string)) == 0)
    {
        name = parsing->clean_line + ft_strlen(cmd_string);
        index_open = ft_charindex(name, '\"');
		error_a(name, parsing, cmd_string);
        index_close = ft_charindex(name + index_open + 1, '\"');
		error_b(name, parsing, cmd_string, content_len);
		ft_strcat_name(name + index_open + 1, header->prog_name, \
		index_close, cmd_string);
		ft_strcat_comment(name + index_open + 1, header->comment, \
		index_close, cmd_string);
    }
}
