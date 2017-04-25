/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:43:34 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/08 18:15:09 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	Skips white spaces and gets the next substring in *line. If that substring
**	is at least 1 character long, it allocates new memory, copies the substring,
**	stores it in *str and returns the length of the substring.
**	If *line contains only whitespaces or is empty, the function returns 0 and
**	no memory allocation is performed.
**	The function returns -1 in case of an error (null input pointers or failed
**	memory allocation).
*/

int		get_next_string(char **line, char **str)
{
	char	*ptr;
	int		count;
	char	*chars_to_skip;
	int		i;

	chars_to_skip = "\t\v\r\f\n ";
	if (!line || !*line || !str)
		return (-1);
	ptr = *line;
	ft_skip_characters(&ptr, chars_to_skip);
	count = 0;
	while (!ft_strchr(chars_to_skip, ptr[count]))
		count++;
	if (count > 0)
	{
		if (!(*str = ft_strnew(count)))
			return (-1);
		i = -1;
		while (++i < count)
			(*str)[i] = *(ptr + i);
		*line = ptr + count;
	}
	return (count);
}
