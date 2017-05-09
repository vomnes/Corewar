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

	size = 0;
	no_player = 2;
	number_players = vm->nb_players;
	tmp = MEM_SIZE / number_players;
	vm_fill_memory(vm, 1, 0);
	while (no_player <= MAX_PLAYERS)
	{
		if (vm->players[no_player].number != 0)
		{
			size = size + tmp;
			vm_fill_memory(vm, no_player, size);
		}
		no_player++;
	}
	print_memory_dump(*vm);
}
