/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:12:00 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/04 15:07:31 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define LINE parsing->clean_line

static int		ft_is_label_chars(int c)
{
	if (ft_strchr(LABEL_CHARS, (char)c) != NULL)
		return (0);
	else
		return (1);
}

static int is_label(t_parsing *parsing, char *content)
{
	char *clean;

	clean = NULL;
	if (!(parsing->label_name = ft_strdup(content)))
	{
		ft_strdel(&content);
		return (-1);
	}
	if (ft_strchr(LINE, ':') != NULL)
		clean = ft_strchr(LINE, ':') + 1;
	if (!(parsing->line_label = ft_strdup(LINE)))
		return (-1);
	ft_strdel(&LINE);
	if (!(LINE = ft_strtrim(clean)))
		return (-1);
	return (1);
}

static int check_label_line(t_parsing *parsing, char *content)
{
	if (content != NULL)
	{
		if (!(ft_isstr_ctype(content, ft_isspace)))
		{
			if (ft_isstr_ctype(content, ft_is_label_chars) != 1)
				return (is_label(parsing, content));
			else if (ft_isstr_ctype(content, ft_is_label_chars) == 1)
			{
				ft_printf("Unauthorised character(s) in label : '%s' - Line %d\n", \
				content, parsing->line_nb);
				return (-1);
			}
		}
	}
	return (0);
}

int parse_labels(t_parsing *parsing)
{
	int i;
	char *content;
    int ret;

	i = 0;
	content = NULL;
    ret = 0;
	while (LINE[i] != '\0')
	{
		if (LINE[i] == ':')
		{
			if (!(content = ft_strndup(LINE, ft_charindex(LINE, ':'))))
				return (-1);
			break ;
		}
		i++;
	}
	ret = check_label_line(parsing, content);
    ft_strdel(&content);
	return (ret);
}
