#include "libft.h"
#include "../shared_files/op.h"
#include "vm.h"

int			print_usage()
{
	ft_printf("Usage: ./corewar ...\n");
	return (0);
}

int			handle_comment(unsigned char buf[16], t_champ *header, char *c, int i)
{
	int len;

	len = ft_strlen(header->comment);
	while (buf[i] == 0 && i < 16)
		i++;
	while (i < 16 && buf[i] != 0)
	{
		if (ft_isprint(buf[i]))
			header->comment[len++] = buf[i];
		i++;
	}
	if (buf[i] == 0 && i < 16)
		*c += 1;
	return (1);
}

int					handle_size(unsigned char buf[16], t_champ *header, char *c, int i)
{
	unsigned char	tab[4];

	while (i++ < 16 && header->count != 0)
		header->count -= 1;
	if (header->count == 0 && i + 3 < 16)
	{
		while (i + 8 < 16)
			i++;
		tab[0] = buf[i + 3];
		tab[1] = buf[i + 2];
		tab[2] = buf[i + 1];
		tab[3] = buf[i];
		header->prog_size = (*(unsigned short*)tab);
		*c += 1;
		i += 4;
	}
	(i < 16) ? handle_comment(buf, header, c, i) : i;
	return (1);
}

int					handle_name(unsigned char buf[16], t_champ *header, char *c, int i)
{
	int				len;

	len = ft_strlen(header->prog_name);
	while (buf[i] == 0 && i < 16)
		i++;
	i -= 1;
	while (++i < 16 && buf[i])
		if (ft_isprint(buf[i]))
			header->prog_name[len++] = buf[i];
	if (buf[i] == 0 && i < 16)
		*c += 1;
	header->count -= i;
	if (i < 16)
		handle_size(buf, header, c, i);
	return (1);
}

int					check_is_correct(unsigned char buf[16], t_champ *header, char *c)
{
	if (*c == 1)
		handle_name(buf, header, c, 0);
	else if (*c == 2)
		handle_size(buf, header, c, 0);
	else if (*c == 3)
		handle_comment(buf, header, c, 0);
	return (0);
}

t_champ					read_files(char **av)
{
	int					fd;
	int					ret;
	char				find;
	unsigned char		buf[16];
	t_champ				header;

	find = 1;
	ret = 0;
	header.count = PROG_NAME_LENGTH + 4;
	ft_memset(&header, 0, sizeof(header_t));
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		perror(0);
		exit(-1);
	}
	while ((ret = read(fd, buf, 16)) > 0)
		check_is_correct(buf, &header, &find);
	if (header.prog_size > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: File %s has too large a code (%d bytes > %d bytes)\n", av[1], header.prog_size, CHAMP_MAX_SIZE);
		exit(-1);
	}
	return (header);
}

int			main(int ac, char **av)
{
	t_champ header;

	ft_memset(&header, 0, sizeof(header_t));
	if (ac < 2)
		return (print_usage());
	header = read_files(av);
	ft_putendl("Introducing contestants...");
	ft_printf("* Player 1, weighing %d bytes, \"%s\" \(\"%s\") !\n", header.prog_size,
			header.prog_name, header.comment);
}
