/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_process_reverse_binary.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:07:36 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/14 14:44:48 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse.h"

static void		rev_stock_instructions_area(size_t size, \
unsigned char buf[size], unsigned int memory[MEMORY_SIZE])
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && buf[i] == 0)
		i++;
	while (i < size)
		memory[j++] = buf[i++];
}

static int		rev_open_file(char *file_name)
{
	int fd;

	fd = 0;
	if (open(file_name, O_DIRECTORY) > 0)
	{
		ft_dprintf(2, "Input can't be a directory\n");
		exit(-1);
	}
	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		ft_dprintf(2, "Can't read source file %s\n", file_name);
		exit(-1);
	}
	return (fd);
}

void			rev_process_reverse_binary(int argc, char **argv)
{
	int				fd;
	size_t			size;
	unsigned char	buf[PROG_NAME_LENGTH + COMMENT_LENGTH + 16];
	unsigned int	memory[MEMORY_SIZE];
	unsigned int	size_prog;

	size = PROG_NAME_LENGTH + COMMENT_LENGTH;
	fd = rev_open_file(argv[FILE]);
	read(fd, buf, size);
	size_prog = rev_parse_header(size, buf);
	size = size_prog + 16;
	size = read(fd, buf, size);
	rev_stock_instructions_area(size, buf, memory);
	rev_transform_instructions(memory, size_prog);
}
