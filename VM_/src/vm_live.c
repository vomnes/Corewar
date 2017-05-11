#include "vm.h"

void		vm_live(t_process *process, t_vm *vm)
{
	int			pc;
 	int			player_nb;
	t_player	*player;

	pc = vm_read_register(process->pc);
	player_nb = vm_read_memory_int(vm, pc + 1, 4);
	player= vm_get_player(vm, player_nb);
	if (player)
	{
	//	ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
//		player_nb, player->name);
		vm->last_live_player_no = player_nb;
	}
	vm->nb_lives_since_last_check += 1;
	process->nb_lives += 1;
	vm_store_in_register(&process->pc, MOD(pc + 5));
}
