#include "vm.h"


// !! Cette fonction suppose que tous les numeros de joueur sont toujours utilises
// entre 1 et nb_players

void	vm_init(t_vm *vm)
{
	int			i;
	t_process	*process;

	i = 1;
	while (i <= vm->nb_players)
	{
		vm_create_process(vm);
		process = vm_get_process(vm, i);
		process->player_no = i;
		vm_store_in_register(&process->registers[1], i);
		i++;
	}
	vm->cycle_to_die = CYCLE_TO_DIE;
}
