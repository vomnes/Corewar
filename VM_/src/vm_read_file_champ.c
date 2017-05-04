#include "vm.h"

void				parse_instruction(size_t size, unsigned char buf[size],\
		t_player *player)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (i < size && buf[i] == 0)
		i++;
	while (i < size)
		player->memory[j++] = buf[i++];
}

char				**vm_read_file_champ(char **av, t_vm *vm, int no_player)
{
	int				fd;
	size_t			size;
	unsigned char	buf[PROG_NAME_LENGTH + COMMENT_LENGTH + 16];
	char			c;

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
	read(fd, buf, size);
	vm_parse_header(size, buf, vm, no_player);
	size = vm->players[no_player].size_player + 16;
	size = read(fd, buf, size);
	parse_instruction(size, buf, &vm->players[no_player]);
	return (av);
}