/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:12:00 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/15 18:25:36 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define LINE parsing->clean_line

static int		is_label(t_parsing *parsing, char *content)
{
	char *clean;

	clean = NULL;
	if (!(parsing->label_name = ft_strdup(content)))
	{
		ft_strdel(&content);
		return (-1);
	}
	if (ft_strchr(LINE, LABEL_CHAR) != NULL)
		clean = ft_strchr(LINE, LABEL_CHAR) + 1;
	if (!(parsing->line_label = ft_strdup(LINE)))
		return (-1);
	ft_strdel(&LINE);
	if (!(LINE = ft_strtrim(clean)))
		return (-1);
	return (1);
}

static int		ft_is_sperator_label(int c)
{
	if (c == DIRECT_CHAR || c == '-')
		return (1);
	if (ft_isspace(c))
		return (1);
	return (0);
}

static int		check_label_line(t_parsing *parsing, char *content)
{
	if (content != NULL)
	{
		if (!(ft_isstr_ctype(content, ft_is_sperator_label)))
		{
			if (ft_isstr_ctype(content, ft_is_label_chars) != 1)
				return (is_label(parsing, content));
			else if (ft_isstr_ctype(content, ft_is_label_chars) == 1)
			{
				ft_dprintf(2, "Unauthorised character(s) in label :");
				ft_dprintf(2, "'%s' - Line %d\n", content, parsing->line_nb);
				return (-1);
			}
		}
	}
	return (0);
}

/*
** parse_labels : Check the validity (exist?) of an label (argument in t_args)
** and set the label_name, line_label in parsing structure.
*/

int				parse_labels(t_parsing *parsing)
{
	int		i;
	char	*content;
	int		ret;

	i = 0;
	content = NULL;
	ret = 0;
	while (LINE[i] != '\0')
	{
		if (LINE[i] == LABEL_CHAR)
		{
			if (!(content = ft_strndup(LINE, ft_charindex(LINE, LABEL_CHAR))))
				return (-1);
			break ;
		}
		i++;
	}
	ret = check_label_line(parsing, content);
	ft_strdel(&content);
	return (ret);
}
