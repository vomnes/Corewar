/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_binary_code.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:56:22 by vomnes            #+#    #+#             */
/*   Updated: 2017/04/27 12:10:34 by vomnes           ###   ########.fr       */
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
	// char **tab;

	line = NULL;
	while (get_next_line(data->input.fd, &line) > 0)
	{
		if (line == NULL || line[0] == '\0')
			continue ;
		ft_putendl(line);
		if (ft_strstr(line, ".name") != NULL)
			get_name(line, data->header.prog_name);
		if (ft_strstr(line, ".comment") != NULL)
			get_comment(line, data->header.comment);
	}
	ft_putendl(data->header.prog_name);
	ft_putendl(data->header.comment);
	binary_header(&data->header, data->binary_file.fd);
	return (0);
}
