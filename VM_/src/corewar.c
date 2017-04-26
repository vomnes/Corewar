/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdady <pdady@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 16:36:40 by pdady             #+#    #+#             */
/*   Updated: 2017/04/25 19:17:19 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../shared_files/op.h"

int			print_usage()
{
	ft_printf("Usage: ./corewar ...\n");
	return (0);
}

int			handle_comment(unsigned char buf[16], header_t *header, char *c, char i)
{
	int len;

	len = ft_strlen(header->comment);
	while (buf[i] == 0 && i < 16)
		i++;
	while (i < 16 && buf[i])
	{
		if (ft_isprint(buf[i]))
			header->comment[len++] = buf[i];
		i++;
	}
	if (buf[i] == 0 && i < 16)
		*c += 1;
	return (1);
}

int			handle_size(unsigned char buf[16], header_t *header, char *c, char i)
{
	int a = 0;
	int b = 0;
	unsigned char tab[2];

	while (buf[i] == 0 && i < 16)
		i += 1;
	if (i < 16)
	{
		tab[1] = buf[i];
		if (i + 1 < 16)
		{
			a = buf[i];
			b = buf[i + 1];
			tab[1] = a;
			tab[0] = b;
			b = (*(unsigned short*)tab);
			header->prog_size = b;
			*c += 1;
			i += 2;
		}
	}
	(i < 16) ? handle_comment(buf, header, c, i) : i;
	return (1);
}

int			handle_name(unsigned char buf[16], header_t *header, char *c, char i)
{
	int len;

	len = ft_strlen(header->prog_name);
	while (buf[i] == 0 && i < 16)
		i++;
	i -= 1;
	while (++i < 16 && buf[i])
		if (ft_isprint(buf[i]))
			header->prog_name[len++] = buf[i];
	if (buf[i] == 0 && i < 16)
		*c += 1;
	if (i < 16)
		handle_size(buf, header, c, i);
	return (1);
}

int			check_is_correct(unsigned char buf[16], header_t *header, char *c, int count)
{
	if (*c == 1)
		handle_name(buf, header, c, 0);
	else if (*c == 2)
		handle_size(buf, header, c, 0);
	else if (*c == 3)
		handle_comment(buf, header, c, 0);
	return (0);
}

header_t					read_files(char **av, int count)
{
	int				fd;
	int				ret;
	char			find;
	unsigned char	buf[16];
	header_t		header;

	find = 1;
	ret = 0;
	ft_memset(&header, 0, sizeof(header_t));
	fd = open(av[1], O_RDONLY);
	while ((ret = read(fd, buf, 16)) > 0)
		check_is_correct(buf, &header, &find, count);
	if (header.prog_size > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: File %s has too large a code (%d bytes > %d bytes)\n", av[1], header.prog_size, CHAMP_MAX_SIZE);
		exit(-1);
	}
	return (header);
}

int			main(int ac, char **av)
{
	int fd = 0;
	char find = 1;
	int count = 0;
	header_t header;

	ft_memset(&header, 0, sizeof(header_t));
	if (ac < 2)
		return (print_usage());
	header = read_files(av, count);
	ft_putendl("Introducing contestants...");
	ft_printf("* Player 1, weighing %d bytes, \"%s\" \(\"%s\") !\n", header.prog_size,
			header.prog_name, header.comment);
}
