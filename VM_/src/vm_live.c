#include "vm.h"

void		vm_live(t_process *process, t_vm *vm)
{
	int			pc;
 	int			player_nb;
	t_player	*player;

	pc = vm_read_register(process->pc);
	player_nb = vm_read_memory_int(vm, pc + 1);
	player= vm_get_player(vm, player_nb);
	if (player)
	{
		if (vm_verbose_lives(vm))
			ft_printf("Player %d (%s) is said to be alive\n",
		player_nb, player->name);
		vm->last_live_player_no = player_nb;
	}
	vm->nb_lives_since_last_check += 1;
	process->nb_lives += 1;
	process->last_live_cycle = vm->cycle_nbr;
	vm_advance_pc(process, vm);
}
