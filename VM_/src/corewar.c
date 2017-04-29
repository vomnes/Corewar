#include "vm.h"

int			print_usage(void)
{
	ft_printf("Usage: ./corewar ...\n");
	return (0);
}

void		pick_size_player(unsigned char *buf, t_player *player)
{
	player->size_player = vm_n_bytes_to_uint(buf, 4);
	if (player->size_player > CHAMP_MAX_SIZE)
	{
		dprintf(2, "Error: champ %s has too large code (%d bytes > %d bytes)\n",
				player->name, player->size_player, CHAMP_MAX_SIZE);
		exit(-1);
	}
}

void		check_exec_magic(unsigned char *buf)
{
	unsigned int nb;
	nb = vm_n_bytes_to_uint(buf, 4);
	if (nb != COREWAR_EXEC_MAGIC)
	{
		ft_putendl_fd("Error: Not a .cor file", 2);
		exit(-1);
	}
}

void		pick_info(size_t size, unsigned char buf[size], t_player *player)
{
	size_t i;
	size_t j;

	i = 4;
	j = 0;
	check_exec_magic(buf);
	while (i < size && i < PROG_NAME_LENGTH)
		player->name[j++] = buf[i++];
	pick_size_player(&buf[i + 8], player);
	i += 12;
	j = 0;
	while (i < size)
		player->comment[j++] = buf[i++];
}

void		parse_header(size_t size, unsigned char buf[size], t_vm *vm, int nb)
{
	size_t i;

	i = 1;
	if (nb >= MAX_PLAYERS)
		vm_error_exit(vm, "Error: too many players");
	if (nb && vm->players[nb].number != 0)
		vm_error_exit(vm, "Error: Number of player already taken");
	vm->players[nb].number = nb;
	pick_info(size, buf, &vm->players[nb]);
}

char		**vm_read_file_champ(char **av, t_vm *vm, int no_player)
{
	int fd;
	size_t size;
	unsigned char buf[PROG_NAME_LENGTH + COMMENT_LENGTH + 16];
	char	c;

	c = 0;
	size = PROG_NAME_LENGTH + COMMENT_LENGTH;
	if (*av && ft_strcmp(*av, "-n") == 0)
	{
		no_player = ft_atoi(av[1]);
		av += 2;
	}
	if ((fd = open(*av, O_RDONLY)) < 0)
	{
		perror(0);
		exit(-1);
	}
	int ret = 0;
	ret = read(fd, buf, size);
	parse_header(size, buf, vm, no_player);
	size = vm->players[no_player].size_player + 16;
	read(fd, buf, size);
	return (av);
}

int main(int ac, char **av)
{
	int		dumps;
	t_vm	vm;
	int count;

	dumps = 0;
	count = 1;
	ft_memset(&vm, 0, sizeof(t_vm));
	if (ac < 2)
		return (print_usage());
	av++;
	if (*av && ft_strcmp(*av, "-d") == 0)
	{
		dumps = ft_atoi(*(++av));
		++av;
	}
	while (*av)
	{
		av = vm_read_file_champ(av, &vm, count);
		count++;
		++av;
	}
	return (0);
}
