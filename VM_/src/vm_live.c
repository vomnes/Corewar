#include "vm.h"

unsigned int		vm_live(t_process *process, t_vm *vm)
{
	unsigned int	pc;
	unsigned int	player_nb;
	char			*player_name;

	pc = vm_read_from_register(process->pc);
	player_nb = vm_n_bytes_to_uint(vm->memory[pc + 1], 4);
	player_name = vm_get_player_name(vm, player_nb);
	if (player_name)
		ft_printf("un processus dit que le joueur %d(%s) est en vie\n")
	vm_store_in_register(&process->pc, MOD(pc + 5));
}
