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
	if (nb > MAX_PLAYERS)
		vm_error_exit(vm, "Error: too many players");
	if (nb && vm->players[nb].number != 0)
		vm_error_exit(vm, "Error: Number of player already taken");
	vm->players[nb].number = nb;
	pick_info(size, buf, &vm->players[nb]);
}

void			print_hexa(size_t size, unsigned char buf[size])
{
	size_t i;
	size_t j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 16)
		{
			ft_printf("%02x ", buf[i]);
			i++;
			j++;
		}
		ft_putchar('\n');
	}
}

void		parse_instruction(size_t size, unsigned char buf[size], t_player *player)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while(i < size && buf[i] == 0)
		i++;
	while (i < size)
		player->memory[j++] = buf[i++];
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
	size = read(fd, buf, size);
	parse_instruction(size, buf, &vm->players[no_player]);
	return (av);
}

char		**parse_line_command(char **av, int *dumps, t_vm *vm)
{
	int count_champs;

	count_champs = 1;
	if (*av && ft_strcmp(*av, "-d") == 0)
	{
		*dumps = ft_atoi(av[1]);
		av = av + 2;
	}
	while (*av)
	{
		av = vm_read_file_champ(av, vm, count_champs);
		count_champs++;
		++av;
	}
	return (av);
}

int			count_number_players(t_vm vm)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (++i < MAX_PLAYERS)
		if (vm.players[i].number != 0)
			count++;
	return (count);
}

void		print_memory_dump(t_vm vm)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < MEM_SIZE)
	{
		j = -1;
		ft_printf("0x%04x : ", i);
		while (++j < 64)
			ft_printf("%02x ", vm.memory[i++]);
		ft_putchar('\n');
	}
}

void		fill_memory(t_vm *vm, int no_player, size_t pos)
{
	size_t i;

	i = 0;
	while (i < vm->players[no_player].size_player)
		vm->memory[pos++] = vm->players[no_player].memory[i++];
}

void		fill_memory_vm(t_vm *vm)
{
	int				number_players;
	unsigned long	size;
	unsigned long	tmp;
	int				no_player;

	size = MEM_SIZE;
	no_player = 2;
	number_players = count_number_players(*vm);
	tmp = size/number_players;
	fill_memory(vm, 1, 0);
	while (no_player < MAX_PLAYERS)
	{
		if (vm->players[no_player].number != 0)
		{
			fill_memory(vm, no_player, tmp);
			tmp = tmp + tmp;
		}
		no_player++;
	}
	print_memory_dump(*vm);
}

int main(int ac, char **av)
{
	int		dumps;
	t_vm	vm;

	dumps = 0;
	ft_memset(&vm, 0, sizeof(t_vm));
	if (ac < 2)
		return (print_usage());
	av++;
	av = parse_line_command(av, &dumps, &vm);
	fill_memory_vm(&vm);
		return (0);
}
