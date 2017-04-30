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

void		parse_instruction(size_t size, unsigned char buf[size], t_player player)
{
	size_t i;
	unsigned char tmp[player.size_player + 16];

	i = 0;
	while(i + 1 < size && buf[i + 1] == 0)
		i++;
	while (++i < size)
		tmp[i] = buf[i];
	player.memory = tmp;
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
	parse_instruction(size, buf, vm->players[no_player]);
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
/*
void		fill_memory_vm(t_vm vm)
{
	int		number_players;
	unsigned long size;

	size = MEM_SIZE;
	number_players = count_number_players(vm);


}
*/
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
		return (0);
}
