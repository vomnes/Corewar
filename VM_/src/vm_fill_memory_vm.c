#include "vm.h"



int			check_pos_pc(t_vm vm, int i)
{
	t_process *process;
	int			value;

	process = vm.processes;
	while (process)
	{
		value = vm_read_register(process->pc);
		if (value == i && value != 0)
			return (1);
		process = process->next;
	}
	return (0);
}

void			print_memory_dump(t_vm vm)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < MEM_SIZE)
	{
		j = -1;
	//	ft_printf("0x%04x : ", i);
		while (++j < 64)
		{
			if (check_pos_pc(vm, i))
				ft_printf("%s%02x %s", RED, vm.memory[i++], DEF);
			else
				ft_printf("%02x ", vm.memory[i++]);
		}
		ft_putchar('\n');
	}
}

void			vm_fill_memory(t_vm *vm, int no_player, size_t pos)
{
	size_t		i;

	i = 0;
	while (i < vm->players[no_player].size_player)
		vm->memory[pos++] = vm->players[no_player].memory[i++];
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
