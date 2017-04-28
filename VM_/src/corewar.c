#include "vm.h"

int			print_usage(void)
{
	ft_printf("Usage: ./corewar ...\n");
	return (0);
}

void		print_hexa(int size, unsigned char buf[size])
{
	int i;
	int j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < 16 && j < size)
		{
			ft_printf("%02x ", buf[j]);
			i++;
			j++;
			if (j == PROG_NAME_LENGTH)
		ft_putchar('\n');
		}
		ft_putchar('\n');
	}
}

void		vm_read_file(char **av)
{
	int fd;
	int number;
	int size;
	unsigned char buf[PROG_NAME_LENGTH + COMMENT_LENGTH + 4];

	number = 0;
	size = PROG_NAME_LENGTH + COMMENT_LENGTH + 4;
	if (*av && ft_strcmp(*av, "-n") == 0)
		number = ft_atoi(*(++av));
	fd = open(*av, O_RDONLY);
	while (read(fd, buf, size) > 0)
	{
		print_hexa(size, buf);
		ft_putstr("\n\n\n");
	}
}

int main(int ac, char **av)
{
	int dumps;

	dumps = 0;
	if (ac < 2)
		return (print_usage());
	av++;
	if (*av && ft_strcmp(*av, "-d") == 0)
	{
		dumps = ft_atoi(*(++av));
		av++;
	}
	vm_read_file(av);
	return (0);
}
