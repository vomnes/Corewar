/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <vomnes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:34:38 by vomnes            #+#    #+#             */
/*   Updated: 2017/04/26 11:51:30 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct s_data
{
	unsigned char octet[4];
}								t_data;

void ft_write_str(int fd, char *str, int len)
{
	int index;
	int word_len;
	char zero;

	index = 0;
	word_len = ft_strlen(str);
	zero = 0;
	while (index < len)
	{
		if (index < word_len)
			write(fd, &(str[index]), 1);
		else
			write(fd, &zero, 1);
		index++;
	}
}

void ft_write_nb(int fd, unsigned int value)
{
	char octet;
	octet = (value >> 24) & 0xFF;
	write(fd, &octet, 1);
	octet = (value >> 16) & 0xFF;
	write(fd, &octet, 1);
	octet = (value >> 8) & 0xFF;
	write(fd, &octet, 1);
	octet = value & 0xFF;
	write(fd, &octet, 1);
}

void ft_print_basic(int fd)
{
	ft_write_nb(fd, 0xea83f3);
	ft_write_str(fd, "zork", PROG_NAME_LENGTH + 4);
	ft_write_nb(fd, 0x014);
	ft_write_str(fd, "just a basic living prog", COMMENT_LENGTH + 4);
}

// 42
// Just a basic Winner Program

int main()
{
	int fd;
	fd = open("binary.cor", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, 0777);
	ft_print_basic(fd);
	ft_write_nb(fd, 0x0b680100);
	ft_write_nb(fd, 0x0f000106);
	ft_write_nb(fd, 0x64010000);
	ft_write_nb(fd, 0x00000101);
	ft_write_nb(fd, 0x01);
  ft_printf("_____________________________________________________________________________\n");
}

// st r1,:buff
// --> [03] [70] [01] [00 49]
// st r6,-4
// --> [03] [70 [06] [ff fc]
// ld :buff,r1
// --> [02 [d0] [00 3f] 01]
// ld %0,r7
// --> [02] [90] 00 00 00 00 [07]
// zjmp %:suite
// --> [09] [00] [37]
//
// r2  --> 01 --> 1 octet
// 23  --> 11 --> 2 octets
// %34 --> 10 --> 4 octets

// r1
// --> 64 01

// 0b 68 01 00 0f 00 01 06  64 01 00 00 00 00 01 01
// 00 00 00 01

// data.o1 = 0xcf;
// data.o2 = 0xfa;
// data.o3 = 0xed;
// data.o4 = 0xfe;
// --> cf 00 00 00 fa 00 00 00 ed 00 00 00 fe 00 00 00

// unsigned char octet[4];
// data.octet[0] = 0xcf;
// data.octet[1] = 0xfa;
// data.octet[2] = 0xed;
// data.octet[3] = 0xfe;
// --> cf fa ed fe

// sti r2,23,%34
// --> 0b 78 02 00 17 00 22
// %directvalue
// : label
