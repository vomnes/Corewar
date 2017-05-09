#include "vm.h"

void				print_memory_dump(t_vm vm)
{
	size_t			i;
	size_t			j;

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

int					count_number_players(t_vm vm)
{
	int				i;
	int				count;

	i = 0;
	count = 0;
	while (++i < MAX_PLAYERS)
		if (vm.players[i].number != 0)
			count++;
	return (count);
}

void				vm_fill_memory(t_vm *vm, int no_player, size_t pos)
{
	size_t		i;

	i = 0;
	while (i < vm->players[no_player].size_player)
		vm->memory[pos++] = vm->players[no_player].memory[i++];
}


//AJOUTER la mise a jour du PC du processus de chaque joueur
void				vm_fill_memory_vm(t_vm *vm)
{
	int				number_players;
	unsigned long	size;
	unsigned long	tmp;
	int				no_player;

	size = MEM_SIZE;
	no_player = 2;
	number_players = count_number_players(*vm);
	tmp = size / number_players;
	vm_fill_memory(vm, 1, 0);
	while (no_player < MAX_PLAYERS)
	{
		if (vm->players[no_player].number != 0)
		{
			vm_fill_memory(vm, no_player, tmp);
			tmp = tmp + tmp;
		}
		no_player++;
	}
	print_memory_dump(*vm);
}
