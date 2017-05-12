#include "vm.h"

void			vm_fill_cells(t_vm *vm, int pos, int player_no)
{
	int			i;

	i = -1;
	while (++i < 4)
		vm->cells[MOD(pos + i)].player_no = player_no;
}

void			vm_fill_memory(t_vm *vm, int no_player, size_t pos)
{
	size_t		i;

	i = 0;
	while (i < vm->players[no_player].size_player)
	{
		vm->cells[pos].player_no = no_player;
		vm->memory[pos++] = vm->players[no_player].memory[i++];
	}
}

void				vm_fill_memory_vm(t_vm *vm)
{
	int				number_players;
	unsigned long	size;
	unsigned long	tmp;
	int				no_player;
	t_process		*process;

	size = 0;
	no_player = 2;
	number_players = vm->nb_players;
	tmp = MEM_SIZE / number_players;
	vm_fill_memory(vm, 1, 0);
	process = vm_get_process(vm, 1);
	vm_store_in_register(&process->pc, size);
	while (no_player <= MAX_PLAYERS)
	{
		if (vm->players[no_player].number != 0)
		{
			size = size + tmp;
			process = vm_get_process(vm, no_player);
			vm_store_in_register(&process->pc, size);
			vm_fill_memory(vm, no_player, size);
		}
		no_player++;
	}
}
