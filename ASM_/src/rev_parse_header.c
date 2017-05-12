/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_parse_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:07:36 by vomnes            #+#    #+#             */
/*   Updated: 2017/05/12 20:05:41 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse.h"

unsigned int	rev_n_bytes_to_uint(unsigned char *ptr, size_t n)
{
	unsigned int	value;
	unsigned int	mask;

	value = 0;
	if (n > 4)
		ft_dprintf(2, "Error: trying to store %lu bytes in an int\n", n);
	while (n > 0)
	{
		value = value << 8;
		mask = (unsigned int)(*ptr);
		value = value | mask;
		ptr++;
		n--;
	}
	return (value);
}

unsigned int	rev_parse_header(size_t size, unsigned char buf[size])
{
	size_t			i;
	size_t			j;
	unsigned int size_prog;

	i = 4;
	j = 0;
	ft_printf("%s \"", NAME_CMD_STRING);
	while (i < size && i < PROG_NAME_LENGTH)
		ft_putchar(buf[i++]);
	ft_printf("\"\n%s \"", COMMENT_CMD_STRING);
	size_prog = rev_n_bytes_to_uint(&buf[i + 8], 4);
	i += 12;
	while (i < size)
		ft_putchar(buf[i++]);
	ft_putstr("\"\n\n");
	return (size_prog);
}

void				rev_parse_instruction(size_t size, unsigned char buf[size], unsigned int memory[1000])
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (i < size && buf[i] == 0)
		i++;
	while (i < size)
		memory[j++] = buf[i++];
}

void	rev_byte_get_arg_type(unsigned int value, char byte[3])
{
	int		byte_offset;
    int     i;

	byte_offset = 6;
    i = 0;
	while (byte_offset >= 2)
	{
		byte[i] = (value >> byte_offset) & 3;
		ft_putnbr(byte[i]);
		ft_putchar(' ');
		byte_offset -= 2;
        i++;
	}
}

void rev_asm(unsigned int 	memory[10000], size_t size_prog)
{
	size_t i;
	short opcode;
	char byte[3];

	i = 0;
	opcode = 0;
	while (i < size_prog)
	{
		opcode = memory[i];
		if (opcode > 16)
			opcode = 0;
		ft_printf("%s ", g_op_tab[opcode].name);
		if (g_op_tab[opcode].param_byte == 1)
			rev_byte_get_arg_type(memory[i + 1], byte);
		// i += g_op_tab[opcode].nb_args;
		i++;
	}
}

void				rev_read_file_champ(int argc, char **argv)
{
	int				fd;
	size_t			size;
	unsigned char	buf[PROG_NAME_LENGTH + COMMENT_LENGTH + 16];
	unsigned int 	memory[10000];
	unsigned int size_prog;
	char			c;

	c = 0;
	size = PROG_NAME_LENGTH + COMMENT_LENGTH;
	if ((fd = open(argv[FILE], O_RDONLY)) < 0)
	{
		perror(0);
		exit(-1);
	}
	read(fd, buf, size);
	size_prog = rev_parse_header(size, buf);
	size = size_prog + 16;
	size = read(fd, buf, size);
	rev_parse_instruction(size, buf, memory);
	rev_asm(memory, size_prog);
}
