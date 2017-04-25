/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_characters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <atrudel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:19:21 by atrudel           #+#    #+#             */
/*   Updated: 2017/03/08 17:43:16 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	Skips all characters specified in the "character" parameter, and then
**	sets the str pointer to the new place in the string. Returns 1 if some
**	characters were skipped, 0 otherwise, and -1 in case of error.
**	This function doesn't work with \0 characters.
*/

int		ft_skip_characters(char **str, char *characters)
{
	int	ret_val;

	if (!str || !characters || !(*str))
		return (-1);
	ret_val = 0;
	while (**str && ft_strchr(characters, **str))
	{
		*str = *str + 1;
		ret_val = 1;
	}
	return (ret_val);
}
