/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:34:38 by vomnes            #+#    #+#             */
/*   Updated: 2017/04/26 19:44:43 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void binary_header(header_t *header, int fd)
{
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_size = 0;
	write_header(fd, *header);
}

void get_name(char *line, char prog_name[PROG_NAME_LENGTH + 1])
{
	int index;
	char flag;
	int i;

	index = 0;
	flag = 0;
	i = 0;
	ft_bzero(prog_name, PROG_NAME_LENGTH + 1);
	while (line[index] != '\0')
	{
		if (line[index] == '\"' && flag == 0)
			flag = 1;
		else if (line[index] == '\"' && flag == 1)
			flag = 0;
		else if (flag == 1)
			prog_name[i++] = line[index];
		index++;
	}
}

void get_comment(char *line, char comment[COMMENT_LENGTH + 1])
{
	int index;
	char flag;
	int i;

	index = 0;
	flag = 0;
	i = 0;
	ft_bzero(comment, COMMENT_LENGTH + 1);
	while (line[index] != '\0')
	{
		if (line[index] == '\"' && flag == 0)
			flag = 1;
		else if (line[index] == '\"' && flag == 1)
			flag = 0;
		else if (flag == 1)
			comment[i++] = line[index];
		index++;
	}
}

int generate_binary_code(t_data *data)
{
	char *line;
	char **tab;

	line = NULL;
	while (get_next_line(data->input.fd, &line) > 0)
	{
		if (line == NULL || line[0] == '\0')
			continue ;
		ft_putendl(line);
		if (!(tab = ft_strsplit(line, ' ')))
			return (-1);
		if (tab[0][0] == '.')
		{
			if (ft_strcmp(tab[0], ".name") == 0)
				get_name(line, data->header.prog_name);
			if (ft_strcmp(tab[0], ".comment") == 0)
				get_comment(line, data->header.comment);
		}
	}
	ft_putendl(data->header.prog_name);
	ft_putendl(data->header.comment);
	binary_header(&data->header, data->binary_file.fd);
	return (0);
}

int main(int argc, char **argv)
{
	t_data data;

	if (open_input(argc, argv, &data.input) == -1)
		return (-1);
	if ((data.binary_file.fd = create_binary_file(data.input)) == -1)
		return (-1);
	if (generate_binary_code(&data) == -1)
		return (-1);
	return (0);
}


// ft_write_nb(fd, 0x0b680100);
// ft_write_nb(fd, 0x0f000106);
// ft_write_nb(fd, 0x64010000);
// ft_write_nb(fd, 0x00000101);
// ft_write_nb(fd, 0x01);
// 42
// Just a basic Winner Program
