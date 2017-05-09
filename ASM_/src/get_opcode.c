/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 11:17:33 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/09 19:35:49 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	pick_up_area(char **content, char *line, char to_analyse, \
int (*type)())
{
	if ((*type)(to_analyse) == 1)
	{
		if (!(*content = ft_strndup(line, ft_charindex(line, to_analyse))))
			return (-1);
		return (1);
	}
	return (0);
}

static int	ft_is_sperator_char(int c)
{
	if (c == DIRECT_CHAR || c == '-')
		return (1);
	else if (ft_isdigit(c))
		return (1);
	else if (ft_isspace(c))
		return (1);
	return (0);
}

static int	pick_up_area_all(char *to_analyse, char **content, int *i)
{
	int ret;

	ret = 0;
	if ((ret = pick_up_area(&(*content), to_analyse, to_analyse[*i], \
	ft_is_sperator_char)) == -1)
		return (-1);
	if (ret == 1)
		return (1);
	return (0);
}

static int	get_code(char *elem)
{
	int index;

	index = 1;
	if (!elem)
		return (-10);
	while (ft_strcmp(g_op_tab[index].name, elem) != 0)
	{
		index++;
		if (index > 16)
			return (-10);
	}
	return (index);
}

int			get_opcode(char *to_analyse, char **opcode_name)
{
	int		i;
	char	*content;
	int		ret;

	i = 0;
	content = NULL;
	ret = 0;
	while (to_analyse[i] != '\0')
	{
		if ((ret = pick_up_area_all(to_analyse, &(*opcode_name), &i)) == -1)
			return (-1);
		if (ret == 1)
			break ;
		i++;
	}
	return (get_code(*opcode_name));
}
