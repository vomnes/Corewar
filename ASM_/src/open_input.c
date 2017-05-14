/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:51:51 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/14 14:59:24 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	open_input_error(char *file_name, int *fd)
{
	char *term;

	if (open(file_name, O_DIRECTORY) > 0)
	{
		ft_dprintf(2, "Input can't be a directory\n");
		return (-1);
	}
	if ((*fd = open(file_name, O_RDONLY)) < 0)
	{
		ft_dprintf(2, "Can't read source file %s\n", file_name);
		return (-1);
	}
	if (ft_strlen(file_name) > 128)
	{
		ft_dprintf(2, "File name too long (> 128 char) %s\n", file_name);
		return (-1);
	}
	if ((term = ft_strstr(file_name, ".s")) == NULL || ft_strlen(term) > 2)
	{
		ft_putendl_fd("Wrong file name - [.s]", 2);
		return (-1);
	}
	return (0);
}

/*
** open_input : Check the input file, it's format and option parameter,
** if the file is good (Not too long, not a directory, .s) and can be open
** stock file name and input fd in t_input.
*/

int			open_input(int argc, char **argv, t_input *input_data)
{
	input_data->fd = 0;
	ft_bzero(input_data->file_name, 129);
	if (open_input_error(argv[FILE], &input_data->fd) == -1)
		return (-1);
	ft_strcat(input_data->file_name, argv[FILE]);
	return (0);
}
